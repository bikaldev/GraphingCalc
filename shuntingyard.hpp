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

class Parser
{
public:
  std::string exp;
  //we can use these two to ease our evaluation.
  std::queue<Token*>infix_expr;
  std::queue<Token*>postfix_expr;
  std::stack<Token*> operator_stack;
  std::stack<Token*> output_stack;
  

public:
    //maybe we can use a get string 
    Parser(std::string s);
    //perhaps we can remove the string used here.
    //perhaps these two need to be void.
    void StringToInfix();
    void InfixToPostfix();
    //perhaps we can call this mutliple times with different values.
    //we dont know the range of data over which is to be evaluated
    //this makes the coding easier, but now we must deal accordingly in the main program.
    //do we create multiple classes or can this be done by the same class.
    double EvaluatePostfix(double x = 0, double y=0);
    //everything that needs to be destroyed needs to be destroyed here.
    ~Parser();
};
