#pragma once

#include "token.hpp"
#include "operand.hpp"
#include "operator.hpp"
#include "leftbracket.hpp"
#include "rightbracket.hpp"
#include "mathfunction.hpp"
#include "variable.hpp"
#include <queue>
#include <stack>
#include "parsedstring.hpp"

// Convert a string to an infix queue
std::queue<Token*> StringToInfix(std::string s);

// Convert an infix queue to a postfix queue
std::queue<Token*> InfixToPostfix(std::queue<Token*> infix);

// Evaluate the postfix queue
double EvaluatePostfix(std::queue<Token*> postfix, double x = 0);

