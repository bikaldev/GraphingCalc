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
queue<Token*> StringToInfix(string s);

// Convert an infix queue to a postfix queue
queue<Token*> InfixToPostfix(queue<Token*> infix);

// Evaluate the postfix queue
double EvaluatePostfix(queue<Token*> postfix, double x = 0, double y = 0);

