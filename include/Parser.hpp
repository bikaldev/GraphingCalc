#pragma once

#include "token.hpp"
#include "operand.hpp"
#include "operator.hpp"
#include "leftbracket.hpp"
#include "rightbracket.hpp"
#include "function.hpp"
#include "variable.hpp"
#include <queue>
#include <stack>
#include "Tokenizer.hpp"

class Parser
{
public:
  std::string exp;
  //we can use these two to ease our evaluation.
  //lets mess with this later.
  std::queue<Token*>infix_exprn;
  std::queue<Token*>postfix_expr;
  std::stack<Token*> operator_stack;
  //this could be the one causing the problem
  //std::stack<Token*> output_stack;
  

public:
    //maybe we can use a get string 
    Parser(std::string s);
    void StringToInfix();
    void InfixToPostfix();
    double EvaluatePostfix(double x = 0, double y=0);
    //everything that needs to be destroyed needs to be destroyed here.
    ~Parser();
};
