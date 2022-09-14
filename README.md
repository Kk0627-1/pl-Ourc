# pl-Ourc
程式介紹:此為中原大學pl程式語言的課堂作業,目的為訓練學生完成大程式的整合,本人學生張純舫完成的作業

程式功能:以c語言,完成直譯器功能,檢查文法,完成指令功能

1、 輸入指令

![image](https://user-images.githubusercontent.com/55129180/190056012-e45fb169-cfd2-4f2d-9281-bdd567058000.png)

   與c語言相似的指令
   
![image](https://user-images.githubusercontent.com/55129180/190056302-148da952-ac9e-49f6-83b0-03516fe90fd2.png)

2、 文法檢查

以學校提供的文法為模本,已成事實作出來,以recursive descend parsing algorithm的方法

user_input 
    : ( definition | statement ) { definition | statement }



definition 
    :           VOID Identifier function_definition_without_ID 
    | type_specifier Identifier function_definition_or_declarators



type_specifier 
    : INT | CHAR | FLOAT | STRING | BOOL

function_definition_or_declarators 
    : function_definition_without_ID
    | rest_of_declarators



rest_of_declarators 
    : [ '[' Constant ']' ] 
      { ',' Identifier [ '[' Constant ']' ] } ';'



function_definition_without_ID 
    : '(' [ VOID | formal_parameter_list ] ')' compound_statement

formal_parameter_list 
    : type_specifier [ '&' ] Identifier [ '[' Constant ']' ] 
      { ',' type_specifier [ '&' ] Identifier [ '[' Constant ']' ] }



compound_statement 
    : '{' { declaration | statement } '}'



declaration 
    : type_specifier Identifier rest_of_declarators



statement
    : ';'     // the null statement
    | expression ';'  /* expression here should not be empty */
    | RETURN [ expression ] ';'
    | compound_statement
    | IF '(' expression ')' statement [ ELSE statement ]
    | WHILE '(' expression ')' statement
    | DO statement WHILE '(' expression ')' ';'
    
    
    
expression
    : basic_expression { ',' basic_expression }



basic_expression
    : Identifier rest_of_Identifier_started_basic_exp
    | ( PP | MM ) Identifier rest_of_PPMM_Identifier_started_basic_exp
    | sign { sign } signed_unary_exp romce_and_romloe
    | ( Constant | '(' expression ')' ) romce_and_romloe



rest_of_Identifier_started_basic_exp
    : [ '[' expression ']' ]
      ( assignment_operator basic_expression 
        | 
        [ PP | MM ] romce_and_romloe 
      )
    | '(' [ actual_parameter_list ] ')' romce_and_romloe



rest_of_PPMM_Identifier_started_basic_exp
    : [ '[' expression ']' ] romce_and_romloe 



sign
    : '+' | '-' | '!'



actual_parameter_list 
    : basic_expression { ',' basic_expression }



assignment_operator
    : '=' | TE | DE | RE | PE | ME



rest_of_maybe_conditional_exp_and_rest_of_maybe_logical_OR_exp // 即romce_and_romloe
    : rest_of_maybe_logical_OR_exp [ '?' basic_expression ':' basic_expression ]



rest_of_maybe_logical_OR_exp 
    : rest_of_maybe_logical_AND_exp { OR maybe_logical_AND_exp }



maybe_logical_AND_exp 
    : maybe_bit_OR_exp { AND maybe_bit_OR_exp }
    
    
rest_of_maybe_logical_AND_exp 
    : rest_of_maybe_bit_OR_exp { AND maybe_bit_OR_exp }



maybe_bit_OR_exp 
    : maybe_bit_ex_OR_exp { '|' maybe_bit_ex_OR_exp }
    
    
rest_of_maybe_bit_OR_exp 
    : rest_of_maybe_bit_ex_OR_exp { '|' maybe_bit_ex_OR_exp }



maybe_bit_ex_OR_exp 
    : maybe_bit_AND_exp { '^' maybe_bit_AND_exp }
    
    
rest_of_maybe_bit_ex_OR_exp 
    : rest_of_maybe_bit_AND_exp { '^' maybe_bit_AND_exp }



maybe_bit_AND_exp 
    : maybe_equality_exp { '&' maybe_equality_exp }
    
    
rest_of_maybe_bit_AND_exp 
    : rest_of_maybe_equality_exp { '&' maybe_equality_exp }



maybe_equality_exp 
    : maybe_relational_exp 
      { ( EQ | NEQ ) maybe_relational_exp}
      
      
rest_of_maybe_equality_exp 
    : rest_of_maybe_relational_exp 
      { ( EQ | NEQ ) maybe_relational_exp }
      
      

maybe_relational_exp 
    : maybe_shift_exp 
      { ( '<' | '>' | LE | GE ) maybe_shift_exp }
      
      
rest_of_maybe_relational_exp 
    : rest_of_maybe_shift_exp 
      { ( '<' | '>' | LE | GE ) maybe_shift_exp }
      
      

maybe_shift_exp 
    : maybe_additive_exp { ( LS | RS ) maybe_additive_exp }
    
    
rest_of_maybe_shift_exp 
    : rest_of_maybe_additive_exp { ( LS | RS ) maybe_additive_exp }
    
    

maybe_additive_exp 
    : maybe_mult_exp { ( '+' | '-' ) maybe_mult_exp }
    
    
rest_of_maybe_additive_exp 
    : rest_of_maybe_mult_exp { ( '+' | '-' ) maybe_mult_exp }
    
    

maybe_mult_exp 
    : unary_exp rest_of_maybe_mult_exp
    
    
rest_of_maybe_mult_exp 
    : { ( '*' | '/' | '%' ) unary_exp }  /* could be empty ! */
    
    

unary_exp
    : sign { sign } signed_unary_exp
    | unsigned_unary_exp
    | ( PP | MM ) Identifier [ '[' expression ']' ]
    
    

signed_unary_exp
    : Identifier [ '(' [ actual_parameter_list ] ')' 
                   |
                   '[' expression ']'
                 ]
    | Constant 
    | '(' expression ')'
    
    

unsigned_unary_exp
    : Identifier [ '(' [ actual_parameter_list ] ')' 
                   |
                   [ '[' expression ']' ] [ ( PP | MM ) ]
                 ]
    | Constant 
    | '(' expression ')'












3、  錯誤情況
根據錯誤我們分成3種情況
1. lexical error 不存在的token
2. syntactical error 文法錯誤
3.  semantic error  使用未定義的identifier做計算


1、 lexical error

   ![image](https://user-images.githubusercontent.com/55129180/190058033-025c0583-ad4e-466f-a2da-7cc49766fa2a.png)
   
2、 syntactical error

   ![image](https://user-images.githubusercontent.com/55129180/190058420-ffe8876f-a03f-4f83-bef4-636d0492c19f.png)

3、 semantic error

   ![image](https://user-images.githubusercontent.com/55129180/190058589-521f3d8d-9937-46b2-89ba-c6530538ef48.png)


