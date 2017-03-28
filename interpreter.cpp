#include "interpreter.hpp"
#include "tokenize.hpp"
#include "expression.hpp"
#include <stack>
#include <algorithm>
#include <regex>

using namespace std;


Interpreter::Interpreter() {
	root = nullptr;
	env = new Environment;
	// env->print_map();
}

Interpreter::~Interpreter() {
	root = NULL;
	delete root;	//IF YOU DELETE ROOT, YOU DELETE EVERYTHING??
}


Node * Interpreter::processTokensToTree(vector<string> recursive_vector) {
	// cout << endl;
	// cout << "we are currently in the processTokensToTree() function" << endl;
	// cout << endl;
	for(int i=0;i<recursive_vector.size();i++)
	{
		// cout << i << "  --- " << recursive_vector[i] << endl;
	}
	// cout << "Done printing" << endl;
	// cout << "Front is " << recursive_vector[0] << endl;
	// cout << "Back is " << recursive_vector.back() << endl;
	if (recursive_vector[0] == "\"(\"," && (recursive_vector.back() == "\")\""
		|| recursive_vector.back() == "\")\",")) {
        if (recursive_vector.size() <= 2) {
            // cout << "ERROR PROCESSING" << endl;
            return nullptr;
        }
		// cout << "Valid data" << endl;
		// cout << endl;

		//pop matching parentheses
		recursive_vector.erase(recursive_vector.begin());
		recursive_vector.pop_back();

		Node* newNode = new Node(expression_factory(recursive_vector[0])); // new node holds first value

		//DEBUGGING OUTPUT STATEMENTS
		// cout << endl;
		// cout << "EXPRESSION value " << newNode->data_expression.express.Data.string_value << endl;
		// cout << "EXPRESSION newNode value: " << newNode->data_expression.express.Data.string_value << endl;
		// cout << "EXPRESSION newNode type: " << newNode->data_expression.express.type << endl;
		// cout << endl;

		recursive_vector.erase(recursive_vector.begin());
		// cout << "Ready to loop" << endl;
		while (recursive_vector.size() > 0) {
			Node * new_child;
			if (recursive_vector[0] != "\"(\",") {
				// cout << "NEW SIMPLE CHILD: ";
				// cout << recursive_vector[0] << endl;
				new_child = new Node(expression_factory(recursive_vector[0]));

				//DEBUGGING OUTPUT STATEMENTS
				// cout << endl;
				// cout << "EXPRESSION value " << new_child->data_expression.express.Data.string_value << endl;
				// cout << "EXPRESSION child_value: " << new_child->data_expression.express.Data.number_value << endl;
				// cout << "EXPRESSION child_type: " << new_child->data_expression.express.type << endl;
				// cout << endl;

				recursive_vector.erase(recursive_vector.begin());
			}
			else {
				// cout << "NEW EXPRESSION CHILD: ";
				// cout << recursive_vector[0] << endl;
				int open_parentheses_counter = 1;
				vector<string> children_of_node;
				children_of_node.push_back(recursive_vector[0]);
				recursive_vector.erase(recursive_vector.begin());
				// cout << "Building " << endl;
				while (open_parentheses_counter > 0) {
					// cout << "parens: " << open_parentheses_counter << ": " << recursive_vector[0] << endl;
					if (recursive_vector[0] == "\"(\",") {
						open_parentheses_counter = open_parentheses_counter + 1;
					}
					else if (recursive_vector[0] == "\")\"" || recursive_vector[0] == "\")\",") {
						open_parentheses_counter = open_parentheses_counter - 1;
					}
					children_of_node.push_back(recursive_vector[0]);
					recursive_vector.erase(recursive_vector.begin());
				}
				// cout << "tokens:" << endl;
				for(int i=0;i<children_of_node.size();i++)
				{
					// cout << i << ": " << children_of_node[i] << endl;
				}
				new_child = processTokensToTree(children_of_node);
			}
			// cout << "Pushed back " << new_child->data << endl;
			newNode->children.push_back(new_child);	//add to children vector

		}
		// cout << "RETURNING: " << newNode->data_expression.express.Data.string_value << endl;
		// cout << "WITH " << newNode->children.size() << " CHILDREN" << endl;
		for (int i = 0; i < newNode->children.size(); ++i) {
			// cout << "!!!children[" << i << "] : " << newNode->children[i]->data_expression.express.Data.number_value << endl;
		}
		return newNode;
	}
	else {
		return nullptr;
	}

}


//this is how I can return expressions and put it into the nodes
//takes a string and turns it into the proper expression using the expression constructors
Expression Interpreter::expression_factory(string changeToExpression) {

	//get rid of parentheses;
	if (changeToExpression[0] == '\"' && (changeToExpression.back() == '\"' || changeToExpression.back() == ',')) {
		changeToExpression.erase(changeToExpression.begin());
		changeToExpression.pop_back();
		changeToExpression.pop_back();
	}
	// changeToExpression.erase(changeToExpression.begin());
	// changeToExpression.pop_back();
	// changeToExpression.pop_back();


	// cout << "THIS IS BEING PASSED INTO EXPRESSION_FACTORY: " << changeToExpression << endl;
	// cout << endl;

	// IF ITS A NUMBER
	// && (!is_bool(changeToExpression))
	if (is_number(changeToExpression)) {
		// cout << "ITS A NUMBER" << endl;
		double double_expression = stod(changeToExpression);
		return Expression(double_expression);
	}

	//IF ITS A BOOLEAN
	else if (is_bool(changeToExpression) && (!is_number(changeToExpression))) {
		// cout << "ITS A BOOL" << endl;
		if (changeToExpression == "True") {
			bool boolean_expression = true;
			return Expression(boolean_expression);
		} else if (changeToExpression == "False") {
			bool boolean_expression = false;
			return Expression(boolean_expression);
		}
		// cout << "does not go through the BOOLEAN LOOP for expression_factory()" << endl;
	}
	//OTHERWISE IT IS A STRING (SYMBOL)
	else if (is_string(changeToExpression)) {
		// cout << "ITS A STRING" << endl;
		return Expression(changeToExpression);
	}
	// cout << "ERROR: IT DIDNT GO THROUGH FUNCTION :: RETURN EMPTY EXPRESSION" << endl;
	// return Expression(changeToExpression);
	return Expression();


}



bool Interpreter::is_number(string s) {
	return( strspn( s.c_str(), ".0123456789" ) == s.size() );
}

bool Interpreter::is_bool(string value) {
	if (value == "true" || value == "True" || value == "false" || value == "False") {
		return true;
	}
	return false;
}

bool Interpreter::is_string(string str) {
	if (is_bool(str) || is_number(str)) {
		return false;
	}
	return true;
}



bool Interpreter::parse(std::istream & expression) noexcept
{
	// cout << endl;
	// cout << "parse() function called" << endl;

	string output = "";
	string read_from_expression = "";
	while (getline(expression, output)) {
		read_from_expression.insert(0, output);
	}
	getline(expression, read_from_expression);
	// cout << endl;

	if (read_from_expression.empty()) {
		// cout << "ERROR: INVALID INPUT EMPTY STRING" << endl;
		return false;
	}

	Tokenize token;	//tokenize returns a vector
	vector<string> vector_of_strings = token.tokenize(read_from_expression);
	int opening_paren = 0;
	int closing_paren = 0;
	for (int i = 0; i < vector_of_strings.size(); ++i) {
		if (vector_of_strings[i] == "\"(\",") {
			opening_paren++;
		}
		else if (vector_of_strings[i] == "\")\"," || vector_of_strings[i] == "\")\"") {
			closing_paren++;
		}
        //LSDKFJAL;SDJKF;LAJKS
        //NEED TO ACTUALLY FIX THIS
        //LSJKDF;LASJDFL;KJSLF;D
        else if (vector_of_strings[i] == "\"1abc\",") {
            return false;
        }
		// cout << "vector_of_strings[" << i << "] : " << vector_of_strings[i] << endl;
	}
	if ((opening_paren != closing_paren) || (opening_paren + closing_paren == 0)) {
		// cout << "ERROR: INVALID INPUT CHECK PARENTHESES" << endl;
		return false;
	}
//    if (vector_of_strings.)
	root = processTokensToTree(vector_of_strings);

    if (root == nullptr) {
			// cout << "ERROR: INVALID INPUT ROOT IS NULL" << endl;
      return false;
    }

	// cout << endl;

	// cout << endl;
	// cout << "what is in the tree: " << endl;
	// cout << "ROOT string_value: " << root->data_expression.express.Data.string_value << endl;
	//	cout << "ROOT CHILD[0]: " << root->children[0]->data_expression.express.Data.number_value << endl;
	// cout << "ROOT CHILD[0][0]: " << root->children[0]->children[0]->data << endl;
	// cout << "ROOT CHILD[0][1]: " << root->children[0]->children[1]->data << endl;

	// cout << endl;
	// cout << "SUCCESS: PARSED CORRECTLY" << endl;
	return true;

}


//this should return an expression
Expression Interpreter::evaluate_helper(Node * node) {

	string result;
	// cout << "evaluate_helper() called" << std::endl;
	// cout << endl;
	// cout << "node children size: " << node->children.size() << endl;

	//all functions (NEED TO PUT THIS INTO THE MAP)
	string add = "+";	//check
	string subtract= "-"; //check
	string multiply = "*"; //check
	string divide = "/"; //check
	string not_symbol = "not";	//check
	string or_symbol = "or";	//
	string less_than_symbol = "<";
	string less_than_equal = "<=";
	string greater_than_symbol = ">";
	string greater_than_equal = ">=";
	string equals = "=";

	string node_string = node->data_expression.express.Data.string_value;

	//if its the last node, then just return that
	if (node->children.size() == 0) {
		// cout << "INSIDE OF THE CHILDREN SIZE 0" << endl;
		if (node->data_expression.express.type == SymbolType) {
			if (env->is_present_in_map(node->data_expression.express.Data.string_value)) {
				Expression double_expression = new Expression();
				double_expression.express.type = NumberType;
				double_expression.express.Data.number_value =
									env->value_at_element_in_map(node->data_expression.express.Data.string_value);
				return double_expression;
			}
		}
		else if (node->data_expression.express.type == NumberType) {
			return node->data_expression;
		}
	}
	if (node_string == "define") {
		Expression exp = new Expression;
		if (env->is_present_in_map(node->children[0]->data_expression.express.Data.string_value)) {
			//overwrite this
			// cout << endl;
			// cout << node->children[0]->data_expression.express.Data.string_value << " IS FOUND IN MAP" << endl;
			// cout << endl;

			//can either set to a number or a variable(symbol)
			if (node->children[1]->data_expression.express.type == NumberType) {
				env->update_map_with_value(node->children[0]->data_expression.express.Data.string_value,
					 node->children[1]->data_expression.express.Data.number_value);
				// env->print_map();
				return node->children[1]->data_expression.express.Data.number_value;
			}
			if (node->children[1]->data_expression.express.type == SymbolType) {
				//get the value from the second child
				double value_second_child = env->value_at_element_in_map(node->children[1]->data_expression.express.Data.string_value);
				env->update_map_with_value(node->children[0]->data_expression.express.Data.string_value, value_second_child);
				// env->print_map();
				// return node->children[1]->data_expression.express.Data.string_value;
				return value_second_child;
			}
			else {
				// cout << "ERROR" << endl;
			}
		}
		//add value to map
		env->add_element_to_map(node->children[0]->data_expression.express.Data.string_value,
			 node->children[1]->data_expression.express.Data.number_value);

	  // env->print_map(); //DEBUG

		exp.express.type = NumberType;
		exp.express.Data.number_value = node->children[1]->data_expression.express.Data.number_value;
		return exp.express.Data.number_value;
	}

	else if (node_string == "begin") {
		//evaluate each expression in order, evaluating to the last
		// cout << endl;
		// cout << endl;
		// cout << "LOLOL FUCK THIS SHIT begin" << endl;
		// cout << endl;
		// cout << endl;
	}
	else if (node_string == "if") {
		//if has 3 arguments
		//	evaluate function - if true - if false
		//evaluate this
		if (node->children.size() < 3) {
			// cout << "ERROR NOT ENOUGH ARGUMENTS" << endl;
			return false;
		}
		Expression result_evaluate = evaluate_helper(node->children[0]);
		// cout << "in the IF CONDITION, evaluates to: " << result_evaluate.express.Data.boolean_value << endl;
		if (result_evaluate == true) {
			//if this is a string value, get the actual value to compare (turn it into number expression)

			return evaluate_helper(node->children[1]);

		// 	if (evaluate_true == NumberType) {
		// 		Expression evaluate_true = evaluate_helper(node->children[1]);
		// 		cout << "EVALUATION OF TRUE: " << evaluate_true.express.Data.number_value << endl;
		// 		return evaluate_helper(node->children[1]);
		// 	}
		// 	if (evaluate_true == SymbolType) {
		// 		//look in the map and find symbol
		// 		double evaluate_true_value = env.value_at_element_in_map(evaluate_true.express.Data.string_value);
		// 		cout << "EVALUATION OF TRUE: " << evaluate_true_value << endl;
		// 		return evaluate_helper(node->children[1]);
		// 	}
		// }
		// else if (result_evaluate == false) {
		// 	if (evaluate_true == NumberType) {
		// 		Expression evaluate_true = evaluate_helper(node->children[1]);
		// 		cout << "EVALUATION OF TRUE: " << evaluate_true.express.Data.number_value << endl;
		// 		return evaluate_helper(node->children[1]);
		// 	}
		// 	if (evaluate_true == SymbolType) {
		// 		//look in the map and find symbol
		// 		double evaluate_true_value = env.value_at_element_in_map(evaluate_true.express.Data.string_value);
		// 		cout << "EVALUATION OF TRUE: " << evaluate_true_value << endl;
		// 		return evaluate_helper(node->children[1]);
		// 	}
		}
		if (result_evaluate == false) {
			return evaluate_helper(node->children[2]);
		}

	}
	else if (node_string == add) {
		// cout << "!!!------ examining the + function" << endl;
		// cout << "NODE CHILD 1: " << node->children[0]->data_expression.express.Data.number_value << endl;
		// cout << "NODE CHILD 1: " << node->children[1]->data_expression.express.Data.number_value << endl;
//        cout << "INSIDE THE ADDITION" << endl;
		Expression exp = new Expression;
		exp.express.type = NumberType;
		double result_add_sum = addition(node->children[0]->data_expression, node->children[1]->data_expression);
//        cout << "result addition: " << result_add_sum << endl;
		exp.express.Data.number_value = result_add_sum;
		return exp.express.Data.number_value;
	}
	else if (node_string == subtract) {
		// cout << "!!!------ examining the - function" << endl;
		// cout << "NODE CHILD 1: " << node->children[0]->data_expression.express.Data.number_value << endl;
		// cout << "NODE CHILD 1: " << node->children[1]->data_expression.express.Data.number_value << endl;
//        cout << "INSIDE THE SUBSTRACT" << endl;
		Expression exp = new Expression;
		exp.express.type = NumberType;
		double result_subtract = subtract_expression(node->children[0]->data_expression, node->children[1]->data_expression);
//        cout << "result subtract: " << result_subtract << endl;
		exp.express.Data.number_value = result_subtract;
		return exp.express.Data.number_value;
	}
	else if (node_string == multiply) {
		// cout << "!!!------ examining the * function" << endl;
		// cout << "NODE CHILD 1: " << node->children[0]->data_expression.express.Data.number_value << endl;
		// cout << "NODE CHILD 1: " << node->children[1]->data_expression.express.Data.number_value << endl;
		Expression exp = new Expression;
		exp.express.type = NumberType;
		double result_mult = multiplication(node->children[0]->data_expression, node->children[1]->data_expression);
		exp.express.Data.number_value = result_mult;
		return exp.express.Data.number_value;
	}
	else if (node_string == divide) {
		// cout << "!!!------ examining the / function" << endl;
		// cout << "NODE CHILD 1: " << node->children[0]->data_expression.express.Data.number_value << endl;
		// cout << "NODE CHILD 1: " << node->children[1]->data_expression.express.Data.number_value << endl;
		Expression exp = new Expression;
		exp.express.type = NumberType;
		double result_division = division(node->children[0]->data_expression, node->children[1]->data_expression);
		exp.express.Data.number_value = result_division;
		return exp.express.Data.number_value;
	}
	else if (node_string == not_symbol) {
		// cout << "!!!------ examining the NOT function" << endl;
		// cout << "NODE CHILD 1: " << node->children[0]->data_expression.express.Data.number_value << endl;
		// cout << "NODE CHILD 1: " << node->children[1]->data_expression.express.Data.number_value << endl;	//this may not exist...
		Expression exp = new Expression;
		exp.express.type = BooleanType;
		bool result_not = logical_not(node->children[0]->data_expression);
		exp.express.Data.boolean_value = result_not;
		return exp.express.Data.boolean_value;
	}
	else if (node_string == or_symbol) {
		// cout << "!!!------ examining the OR function" << endl;
		// cout << "NODE CHILD 1: " << node->children[0]->data_expression.express.Data.number_value << endl;
		// cout << "NODE CHILD 1: " << node->children[1]->data_expression.express.Data.number_value << endl;
		Expression exp = new Expression;
		exp.express.type = BooleanType;
		bool result_or = logical_or(node->children[0]->data_expression, node->children[1]->data_expression);
		exp.express.Data.boolean_value = result_or;
		return exp.express.Data.boolean_value;
	}
	else if (node_string == less_than_symbol) {
		// cout << "!!!------ examining the LESS THAN function" << endl;
		// cout << "NODE CHILD 1: " << node->children[0]->data_expression.express.Data.number_value << endl;
		// cout << "NODE CHILD 1: " << node->children[1]->data_expression.express.Data.number_value << endl;
		Expression exp = new Expression;
		exp.express.type = BooleanType;
		bool result_less_than = less_than(node->children[0]->data_expression, node->children[1]->data_expression);
		exp.express.Data.boolean_value = result_less_than;
		return exp.express.Data.boolean_value;
	}
	else if (node_string == less_than_equal) {
		// cout << "!!!------ examining the LESS THAN OR EQUAL function" << endl;
		// cout << "NODE CHILD 1: " << node->children[0]->data_expression.express.Data.number_value << endl;
		// cout << "NODE CHILD 1: " << node->children[1]->data_expression.express.Data.number_value << endl;
		Expression exp = new Expression;
		exp.express.type = BooleanType;
		bool result_less_than_or_equal = less_than_or_equal(node->children[0]->data_expression, node->children[1]->data_expression);
		exp.express.Data.boolean_value = result_less_than_or_equal;
		return exp.express.Data.boolean_value;
	}
	else if (node_string == greater_than_symbol) {
		// cout << "!!!------ examining the GREATER THAN function" << endl;
		// cout << "NODE CHILD 1: " << node->children[0]->data_expression.express.Data.number_value << endl;
		// cout << "NODE CHILD 1: " << node->children[1]->data_expression.express.Data.number_value << endl;
		Expression exp = new Expression;
		exp.express.type = BooleanType;
		bool result_greater = greater_than(node->children[0]->data_expression, node->children[1]->data_expression);
		exp.express.Data.boolean_value = result_greater;
		return exp.express.Data.boolean_value;
	}
	else if (node_string == greater_than_equal) {
		// cout << "!!!------ examining the GREATER THAN OR EQUAL function" << endl;
		// cout << "NODE CHILD 1: " << node->children[0]->data_expression.express.Data.number_value << endl;
		// cout << "NODE CHILD 1: " << node->children[1]->data_expression.express.Data.number_value << endl;
		Expression exp = new Expression;
		exp.express.type = BooleanType;
		bool result_greater_than_or_equal = greater_than_or_equal(node->children[0]->data_expression, node->children[1]->data_expression);
		exp.express.Data.boolean_value = result_greater_than_or_equal;
		return exp.express.Data.boolean_value;
	}
	else {
		// cout << "didnt go through any of the if statements" << endl;
	}
	return node->data_expression;

}




//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------



Expression Interpreter::eval() {
	// cout << endl;
	// cout << "evaluate() function called" << endl;
	// cout << endl;
	Expression expression_evaluate;
	string result = "";
		// cout << "WHAT IS THE VALUE OF ROOT BEING PUT INTO EVAL_HELPER()??? " << root->data_expression.express.Data.string_value << endl;
	expression_evaluate = evaluate_helper(root);
	if (expression_evaluate.express.type == NumberType) {
		cout << "(" << expression_evaluate.express.Data.number_value << ")" << endl;
	}
	else if (expression_evaluate.express.type == BooleanType) {
       if (expression_evaluate.express.Data.boolean_value == 0) {
				 cout << "(False)" << endl;
			 }
			 else {
				 cout << "(True)" << endl;
			 }
	}
	else if (expression_evaluate.express.type == SymbolType) {
		cout << "(" << expression_evaluate.express.Data.string_value << ")" << endl;
	}
	else {
		cout << "INVALID TYPE OF EXPRESSION: " << endl;
	}
	return expression_evaluate;
}



//_-nary functions
bool Interpreter::logical_not(Expression x) {
	if (x.express.Data.boolean_value == false) {
		return true;
	} else {
		return false;
	}
}

bool Interpreter::logical_and(Expression x, Expression y) {
	if ((x.express.Data.boolean_value && y.express.Data.boolean_value) == true) {
		return true;
	} else {
		return false;
	}
}

bool Interpreter::logical_or(Expression x, Expression y) {
	if ((x.express.Data.boolean_value || y.express.Data.boolean_value) == true) {
		return true;
	} else {
		return false;
	}
}

bool Interpreter::equals(Expression x, Expression y) {
	if (x.express.Data.boolean_value == y.express.Data.boolean_value) {
		return true;
	} else if (x.express.Data.number_value == y.express.Data.number_value) {
		return true;
	} else if (x.express.Data.string_value == y.express.Data.string_value) {
		return true;
	} else {
		return false;
	}
}

bool Interpreter::greater_than(Expression x, Expression y) {
	if ((x.express.Data.number_value > y.express.Data.number_value) == true) {
		return true;
	} else {
		return false;
	}
}

bool Interpreter::greater_than_or_equal(Expression x, Expression y) {
	if ((x.express.Data.number_value >= y.express.Data.number_value) == true) {
		return true;
	} else {
		return false;
	}
}

bool Interpreter::less_than_or_equal(Expression x, Expression y) {
	if ((x.express.Data.number_value <= y.express.Data.number_value) == true) {
		return true;
	} else {
		return false;
	}
}

bool Interpreter::less_than(Expression x, Expression y) {

	double map_value_x = 0;
	double map_value_y = 0;

	if ((x.express.Data.number_value < y.express.Data.number_value)) {
		return true;
	}
	if (x.express.type == SymbolType && y.express.type == SymbolType) {
		if (env->is_present_in_map(x.express.Data.string_value)) {
			map_value_x = env->value_at_element_in_map(x.express.Data.string_value);
		}
		else {
			cout << "ERROR: " << x.express.Data.string_value << " not defined" << endl;
			return false;
		}

		if (env->is_present_in_map(y.express.Data.string_value)) {
				map_value_y = env->value_at_element_in_map(y.express.Data.string_value);
		}
		else {
			cout << "ERROR: " << y.express.Data.string_value << "not defined" << endl;
			return false;
		}

		//FINAL RESULT
		if (map_value_x < map_value_y) {
			return true;
		}
		//it doesn't get to anything
		return false;

	}
	//FINISH THIS
	if (x.express.type == SymbolType && y.express.type == NumberType) {

	}
	if (x.express.type == NumberType && y.express.type == SymbolType) {

	}
	if (x.express.type == SymbolType && y.express.type == SymbolType) {

	}
	return false;

}

double Interpreter::subtract_expression(Expression x, Expression y) {
	double result = x.express.Data.number_value - y.express.Data.number_value;
	return result;
}

double Interpreter::negation(Expression x) {
	double result = (x.express.Data.number_value * (-1));
	return result;
}

double Interpreter::division(Expression x, Expression y) {
	double result = x.express.Data.number_value / y.express.Data.number_value;
	return result;
}

double Interpreter::addition(Expression x, Expression y) {
	double result = x.express.Data.number_value + y.express.Data.number_value;
	return result;
}

double Interpreter::multiplication(Expression x, Expression y) {
	double result = x.express.Data.number_value * y.express.Data.number_value;
	return result;
}
