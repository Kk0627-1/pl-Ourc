# include <vector>
# include <string>
# include <iostream>
# include <sstream>
# include <stdio.h> 
# include <string.h> 
# include <ctype.h>
# include <stdlib.h>
# include <math.h>
# include <iomanip>
using namespace std;
static int u_loc = 0;

struct Token{
  // type 
  string type;
  // token
  string token;
  // sign
  string sign;
  // function data, data, arrary
  string function_data;
  // arrary's size
  string size_str;
  // select loc of arrary[ ]
  string select_arrary_num;
  double grade;
  string str_value;
  double num_value;
  // is it assign
  bool is_assign ;
  bool is_get;
  bool assigned_value;
  // check is it float
  bool isfloat;
  bool is_million;
  // check is it arrary
  bool is_arrary;
  int line;
  // initial token , find ide_name
  vector<Token> initial_data;
  // to put function token
  vector<Token> data;
  // arrary is vector type
  vector<Token> arrary_data;

} ;


// nothing
struct Operator_data{
  string exp;
  Token value1;
  Token value2;
};

// nothing
struct Cin_Cout_data{
  Token ide;
  Token value;
};

// nothing
struct While_Need_Data{
  Operator_data operator_data;
  Cin_Cout_data cin_cout_data;
  bool is_operator;
  bool is_assign_operator;
  bool is_cin;
  bool is_cout;
};

// one to put ide_name, one put value
struct Value{
  Token token_name;
  Token value;
};

// creat for m_definition_list
// check is it is_rebuild
struct Data{
  string str;
  bool is_rebuild;
  bool is_function;
};

// nothing
struct Arrary_num{
  Token token_name;
  string size_str;
  vector<Token> arrary_value;
};

static char u_ch ;
typedef vector<Token> Tokenline ;
typedef vector<Tokenline> Instruction ;



class Project{
  // for peek data
  Token m_peek_token;
  Token m_PP_token;
  Token m_MM_token;
  // vector<Arrary_num> m_arrary_table;
  // vector<Arrary_num> m_tmp_arrary_table ;
  
  // nothing
  vector<While_Need_Data> m_While_Need_Data_list;
  // save while condition token
  vector<Token> m_while_condition;
  // save while statement token
  vector<Token> m_while_statement;
  // save cin token
  vector<Token> m_cin_token;
  // save cout token
  vector<Token> m_cout_token;
  // save function, function ide name...
  vector<Token> m_fuction_table;
  // save define ide name
  // save define ide value
  vector<Value> m_define_table;
  
  // nothing
  vector<Token> m_PP_table;
  vector<Token> m_MM_table;
  
  // save localDat ide name
  // save localDat ide value
  vector<Value> m_localData_table;
  
  // nnothing
  vector<Token> m_parameter_table;
  // nothing
  vector<Token> m_functData_table;
  
  // save this definition data
  vector<Data> m_definition_list;
  // for 'InputBufferAppend'
  vector<string> m_input_buffer; 
  // ?: , vector bool
  vector<bool> m_shouldnot_operator_list;
  // if , vector bool
  vector<bool> m_shouldnot_operator_list2;
  string m_instruction_str;
  // for listfunction
  string m_select_funct;
  string m_type ;
  // for error line
  int m_now_line;
  // for function data
  int m_space_num ;
  // for while condition loc
  int m_expression_loc;
  // for while statement loc
  int m_statement_loc;
  double m_now_m_token_m_loc ;
  // for GetToken
  char m_now_ch_from_string; 
  bool m_compoundStatement ;
  // is in {} do define
  bool m_declaration;
  bool m_is_while;
  bool m_is_if;
  // now GetToken but get from condition vector
  bool m_while_getExpression;
  // now GetToken but get from statement vector
  bool m_while_getStatement;
  // now save Token to condition vector
  bool m_is_while_condition;
  // now save Token to statement vector
  bool m_is_while_statement;
  bool m_shouldnot_operator;
  // coondition for ide is "cin"
  bool m_is_cin ;
  // coondition for ide is "cout"
  bool m_is_cout ;
  bool m_unrecognized_exist;
  // chech is it unexpected
  bool m_unexpected ;
  // now is function
  bool m_function ;
  // Get ( VOID,INT...)
  bool m_now_definition ;
  // NOTHING
  bool m_now_parameter ;
  bool m_undefined_ide ;
  // Is ListFunction
  bool m_ListFunction ;
  // Is ListAllFunctions
  bool m_ListAllFunctions ;
  // Is ListVariable
  bool m_ListVariable ;
  // Is ListAllVariables
  bool m_ListAllVariables ;
  bool m_is_Done;
  // is peek,but no GetToken
  bool m_is_peek;
  bool m_decimal_point; 
  bool m_is_quit ;
  bool m_finish;
  bool m_is_has_semicolon ;
  bool m_IsEOF ;
  // Get Token
  void GetToken( Token & token ) ;
  // Peek Token
  void PeekToken() ;
  // skip "\n" after to ";" 
  void Skip_final_line() ;
  // Get Value from m_define_table, m_localData_table ....
  void GetValue( Token & token ) ;
  // Set Value to m_define_table, m_localData_table ....
  void SetValue( Token & token_name, Token & token_value ) ;
  // input_buffer to  Cin data
  void CinData( vector<Token> tokenlist ) ;
  // cout data
  void CoutData( vector<Token> & tokenlist ) ;
  // set type for constant
  // like : num_constant,bool_cinstant....
  void SetType( Token & token ) ;
  // Operation
  void Operator( Token & value1, Token & value2, string exp ) ;
  // like: <,>,>=....
  void Relation( Token & value1, Token & value2, string exp ) ;
  //Operation with  -,+,!
  // and get value for token
  void Sign_Value( Token & value, Token & sign ) ;
  // token not add 1,but define data add 1
  void Do_Last_PP( Token token ) ;
  // token not - 1,but define data - 1
  void Do_Last_MM( Token token ) ;
  // token  add 1,and define data add 1
  void Do_First_PP( Token & token ) ;
  // token  - 1,and define data - 1
  void Do_First_MM( Token & token ) ;
  // do operation,like : =,+=,-=...
  void AssignOperator( Token & value1, Token & value2, string & exp ) ;
  // Token have arrary_data, but it's size is 0 in initialy
  // so use Token's arrary size from data,creat it's size
  void SetArraryData() ;
  // Num To String(double)
  string NumToString( double num ) ;
  // Num To String(int)
  string NumToString( int num ) ;
  // for , ?: , check is true
  // when m_shouldnot_operator_list all is false, return true;
  bool Allow_before_m_shouldnot_operator_list() ;
  // for , if , check is true
  // when m_shouldnot_operator_list2 all is false, return true;
  bool Allow_before_m_shouldnot_operator_list2() ;
  /*
  void BooleanExp( bool & correct ) ;
  void Exp( bool & correct, double & value );
  void Term( bool & correct, double & value );
  void Factor( bool & correct, double & value );
  */
  
  // now cin.get() is belong IDENT type,get
  // get char until "\n", " ",....
  void IDENT( string  & str  ) ;
  // now cin.get() is belong Num type,get
  // get char until "\n", " ",....
  void Num( string  & str ) ;
  // skip char , if char is " ", //....., "\n"
  // and evalute error line
  void Skip_Whitespace() ;
  // abort char until "\n"
  // because condition is error
  void Skip_Line() ;
  // put Token to function_table,define_table....
  void Creat_define_table() ;
  // do Is_User_Input,and do undefined_error
  void Execute() ;
  // show all Functions
  void ListAllFunctions() ;
  // show the selected data
  void ListFunction() ;
  // show all Variables, not include "cin","cout"
  void ListAllVariables() ;
  // show the selected Variable
  void ListVariable() ;
  
  void Is_User_Input( bool & correct ) ;
  void Is_Definition( bool & correct, bool & Is_Get ) ;
  void Is_Statement( bool & correct, bool & Is_Get ) ;
  void Is_Sign( bool & correct, bool & Is_Get, Token & value ) ;
  void Is_Function_definition_without_ID( bool & correct, bool & Is_Get ) ;
  void Is_Type_specifier( bool & correct, bool & Is_Get ) ;
  void Is_Function_definition_or_declarators( bool & correct, bool & Is_Get ) ;
  void Is_Rest_of_declarators( bool & correct, bool & Is_Get ) ;
  void Is_Formal_parameter_list( bool & correct, bool & Is_Get ) ;
  void Is_Compound_statement( bool & correct, bool & Is_Get ) ;
  void Is_Declaration( bool & correct, bool & Is_Get ) ;
  void Is_Expression( bool & correct, bool & Is_Get, Token & value ) ;
  void Is_Basic_expression( bool & correct, bool & Is_Get, Token & value ) ;
  void Is_Rest_of_Identifier_started_basic_exp( bool & correct, bool & Is_Get, Token & value ) ; 
  void Is_Rest_of_PPMM_Identifier_started_basic_exp( bool & correct, 
                                                     bool & Is_Get, 
													 Token & value, 
													 string & exp ) ;
  void Is_Signed_unary_exp( bool & correct, bool & Is_Get, Token & value, Token & sign ) ;
  // void Is_Romce_and_romloe( bool & correct, bool & Is_Get ) ;
  void Is_Assignment_operator( bool & correct, bool & Is_Get, string & value ) ;
  void Is_Actual_parameter_list( bool & correct, bool & Is_Get ) ;
  void Is_Rest_of_maybe_conditional_exp_and_rest_of_maybe_logical_OR_exp( bool & correct, 
                                                                          bool & Is_Get, 
																		  Token & value ) ;
  void Is_Rest_of_maybe_logical_OR_exp( bool & correct, bool & Is_Get, Token & value ) ;
  void Is_Rest_of_maybe_logical_AND_exp( bool & correct, bool & Is_Get, Token & value ) ;
  void Is_Maybe_logical_AND_exp( bool & correct, bool & Is_Get, Token & value ) ;
  void Is_Rest_of_maybe_bit_OR_exp( bool & correct, bool & Is_Get, Token & value ) ;
  void Is_Maybe_bit_OR_exp( bool & correct, bool & Is_Get, Token & value ) ;
  void Is_Maybe_bit_ex_OR_exp( bool & correct, bool & Is_Get, Token & value ) ;
  void Is_Rest_of_maybe_bit_ex_OR_exp( bool & correct, bool & Is_Get, Token & value ) ;
  void Is_Maybe_bit_AND_exp( bool & correct, bool & Is_Get, Token & value ) ;
  void Is_Rest_of_maybe_bit_AND_exp( bool & correct, bool & Is_Get, Token & value ) ;
  void Is_Maybe_equality_exp( bool & correct, bool & Is_Get, Token & value ) ;
  void Is_Rest_of_maybe_equality_exp( bool & correct, bool & Is_Get, Token & value ) ;
  void Is_Maybe_relational_exp( bool & correct, bool & Is_Get, Token & value ) ;
  void Is_Maybe_shift_exp( bool & correct, bool & Is_Get, Token & value ) ;
  void Is_Rest_of_maybe_relational_exp( bool & correct, bool & Is_Get, Token & value ) ;
  void Is_Rest_of_maybe_shift_exp( bool & correct, bool & Is_Get, Token & value ) ;
  void Is_Maybe_additive_exp( bool & correct, bool & Is_Get, Token & value ) ;
  void Is_Rest_of_maybe_additive_exp( bool & correct, bool & Is_Get, Token & value ) ;
  void Is_Maybe_mult_exp( bool & correct, bool & Is_Get, Token & value ) ;
  void Is_Rest_of_maybe_mult_exp( bool & correct, bool & Is_Get, Token & value ) ;
  void Is_Unary_exp( bool & correct, bool & Is_Get, Token & value ) ;
  void Is_Unsigned_unary_exp( bool & correct, bool & Is_Get, Token & value ) ;
  
  bool Is_Letter( char ch ) ;
  bool Is_Sign( char ch ) ;
  bool Is_for_IDENT( char ch ) ;
  bool Is_for_Num( char ch ) ;
  // according ide name give type
  // when ide is "int","string",..., m_now_definition is true
  void Is_Definition( Token & token ) ;
  bool Is_symbol_for_token( string  & m_nowtoken ) ;
  Tokenline m_tokenline ;
  vector<Tokenline> m_tokenline_list ;
  public:
  Project() ;
  // vector<Tokenline> m_tokenline_list ;
  // vector<Instruction> m_instruction_list ;
  
  
};


Project::Project() {
  m_instruction_str = "";
  m_select_funct = "";
  m_type = "";
  m_now_line = 1;
  m_space_num = 0;
  m_expression_loc = 0;
  m_statement_loc = 0;
  m_compoundStatement = false;
  m_declaration = false;
  m_is_if = false;
  m_is_while = false;
  m_is_while_condition = false;
  m_while_getExpression = false;
  m_while_getStatement = false;
  m_is_while_statement = false;
  m_shouldnot_operator = false;
  m_is_cin = false;
  m_unexpected = false;
  m_unrecognized_exist = false;
  m_ListVariable = false;
  m_ListAllVariables = false;
  m_ListFunction = false;
  m_ListAllFunctions = false;
  m_now_definition = false;
  m_now_parameter = false;
  m_undefined_ide = false;
  m_is_peek = false;
  m_IsEOF = false;
  m_is_quit = false;
  m_decimal_point = false;
  m_is_Done = false;
  m_now_m_token_m_loc = 0;
  m_now_ch_from_string = '\0';
  m_is_has_semicolon = false;
  m_finish = false;
  int m_loc = -1;
  Creat_define_table();
  Execute();
  /*
  cout << "\n";
  
  for ( int i = 0; i < m_fuction_table.size() ; i++ ) {
    cout << m_fuction_table[i].token << "\n";
    cout << m_fuction_table[i].function_data;
    cout << "\n";
  } // for
  */
  

  
} // Project::Project()

// check m_shouldnot_operator_list2 all is false
// belong for if
bool Project::Allow_before_m_shouldnot_operator_list2() {
  bool success = true;
  for ( int i = 0; i < m_shouldnot_operator_list2.size() ; i++ ) {
  	if ( m_shouldnot_operator_list2[i] == true ) {
  	  success = false;
	} // if
	
  } // for
  

  return success;
  
} // Project::Allow_before_m_shouldnot_operator_list2()

// check m_shouldnot_operator_list all is false
// belong for ?:
bool Project::Allow_before_m_shouldnot_operator_list() {
  bool success = true;
  for ( int i = 0; i < m_shouldnot_operator_list.size() - 1 ; i++ ) {
  	if ( m_shouldnot_operator_list[i] == true ) {
  	  success = false;
	} // if
	
  } // for
  
  return success;
  
} // Project::Allow_before_m_shouldnot_operator_list()


// push_back data to Token.arrary_data
// when is_arrary is true
void Project::SetArraryData() {
  Token tmp_token;
  for ( int i = 0; i < m_define_table.size() ; i++ ) {
    if ( m_define_table[i].value.is_arrary == true ) {
      for ( int j = 0; j < atoi( m_define_table[i].value.size_str.c_str() ) ; j++ ) {
      	m_define_table[i].value.arrary_data.push_back( tmp_token );
	  } // for
	  
	} // if
	
  } // for
  
} // Project::SetArraryData()




// when not happen if, and ?:, do assign operation
// when happen if or ?:, but now can operation, do assign operation
void Project::AssignOperator( Token & value1, Token & value2, string & exp ) {
  if ( m_shouldnot_operator_list.size() == 0 && Allow_before_m_shouldnot_operator_list2() == true ) {
  	Token token_name = value1;
    Token token_value;
    
    While_Need_Data while_need_data;
  	while_need_data.is_operator = true;
  	while_need_data.operator_data.exp = exp;
  	while_need_data.operator_data.value1 = value1;
  	while_need_data.operator_data.value2 = value2;
  	m_While_Need_Data_list.push_back( while_need_data );
    
    
    GetValue( value1 );
    SetType( value1 );
    GetValue( value2 );
    SetType( value2 );
    if ( strcmp( exp.c_str(), "=" ) == 0 ) {
      value1 = value2;
      token_value = value1;
	} // if
	
    
    else if ( strcmp( exp.c_str(), "+=" ) == 0 ) {
  	  if ( strcmp( value1.type.c_str(), "STRING_CONSTANT" ) == 0 ) {
  	    value1.token = value1.token + value2.token ;
        token_value = value1;
        token_value.isfloat = false;
  	  
	  } // if
  	
  	  else if ( value1.isfloat == true || value2.isfloat == true ) {
        value1.token = NumToString( atof( value1.token.c_str() ) + atof( value2.token.c_str() ) );
        token_value = value1;
        token_value.isfloat = true;
      } // else if
    
      else {
        value1.token = NumToString( atoi( value1.token.c_str() ) + atoi( value2.token.c_str() ) );
        token_value = value1;
        token_value.isfloat = false;
	  } // else
    
    } // else if
  
    else if ( strcmp( exp.c_str(), "-=" ) == 0 ) {
  	  if ( value1.isfloat == true || value2.isfloat == true ) {
        value1.token = NumToString( atof( value1.token.c_str() ) - atof( value2.token.c_str() ) );
        token_value = value1;
        token_value.isfloat = true;
      } // if
    
      else {
        value1.token = NumToString( atoi( value1.token.c_str() ) - atoi( value2.token.c_str() ) );
        token_value = value1;
        token_value.isfloat = false;
	  } // else
	
    } // else if
  
    else if ( strcmp( exp.c_str(), "*=" ) == 0 ) {
  	  if ( value1.isfloat == true || value2.isfloat == true ) {
        value1.token = NumToString( atof( value1.token.c_str() ) * atof( value2.token.c_str() ) );
        token_value = value1;
        token_value.isfloat = true;
      } // if
    
      else {
        value1.token = NumToString( atoi( value1.token.c_str() ) * atoi( value2.token.c_str() ) );
        token_value = value1;
        token_value.isfloat = false;
	  } // else
	
    } // else if
  
    else if ( strcmp( exp.c_str(), "/=" ) == 0 ) {
  	  if ( value1.isfloat == true || value2.isfloat == true ) {
        value1.token = NumToString( atof( value1.token.c_str() ) / atof( value2.token.c_str() ) );
        token_value = value1;
        token_value.isfloat = true;
      } // if
    
      else {
        value1.token = NumToString( atoi( value1.token.c_str() ) / atoi( value2.token.c_str() ) );
        token_value = value1;
        token_value.isfloat = false;
	  } // else
	
    } // else if
  
    else if ( strcmp( exp.c_str(), "%=" ) == 0 ) {
      value1.token = NumToString( atoi( value1.token.c_str() ) % atoi( value2.token.c_str() ) );
      token_value = value1;
      token_value.isfloat = false;
	
    } // else if
  
    token_value.is_assign = true;
    SetValue( token_name, token_value ) ;
    
  } // if
	
	
  else if ( m_shouldnot_operator_list.size() == 1 &&
            m_shouldnot_operator_list[ m_shouldnot_operator_list.size() - 1 ] == false &&
            Allow_before_m_shouldnot_operator_list2() == true ) {
  	Token token_name = value1;
    Token token_value;
    While_Need_Data while_need_data;
  	while_need_data.is_operator = true;
  	while_need_data.operator_data.exp = exp;
  	while_need_data.operator_data.value1 = value1;
  	while_need_data.operator_data.value2 = value2;
  	m_While_Need_Data_list.push_back( while_need_data );
  	
    GetValue( value1 );
    SetType( value1 );
    GetValue( value2 );
    SetType( value2 );
    if ( strcmp( exp.c_str(), "=" ) == 0 ) {
      value1 = value2;
      token_value = value1;
	} // if
    
    else if ( strcmp( exp.c_str(), "+=" ) == 0 ) {
  	  if ( strcmp( value1.type.c_str(), "STRING_CONSTANT" ) == 0 ) {
  	    value1.token = value1.token + value2.token ;
        token_value = value1;
        token_value.isfloat = false;
  	  
	  } // if
  	
  	  else if ( value1.isfloat == true || value2.isfloat == true ) {
        value1.token = NumToString( atof( value1.token.c_str() ) + atof( value2.token.c_str() ) );
        token_value = value1;
        token_value.isfloat = true;
      } // else if
    
      else {
        value1.token = NumToString( atoi( value1.token.c_str() ) + atoi( value2.token.c_str() ) );
        token_value = value1;
        token_value.isfloat = false;
	  } // else
    
    } // else if
  
    else if ( strcmp( exp.c_str(), "-=" ) == 0 ) {
  	  if ( value1.isfloat == true || value2.isfloat == true ) {
        value1.token = NumToString( atof( value1.token.c_str() ) - atof( value2.token.c_str() ) );
        token_value = value1;
        token_value.isfloat = true;
      } // if
    
      else {
        value1.token = NumToString( atoi( value1.token.c_str() ) - atoi( value2.token.c_str() ) );
        token_value = value1;
        token_value.isfloat = false;
	  } // else
	
    } // else if
  
    else if ( strcmp( exp.c_str(), "*=" ) == 0 ) {
  	  if ( value1.isfloat == true || value2.isfloat == true ) {
        value1.token = NumToString( atof( value1.token.c_str() ) * atof( value2.token.c_str() ) );
        token_value = value1;
        token_value.isfloat = true;
      } // if
    
      else {
        value1.token = NumToString( atoi( value1.token.c_str() ) * atoi( value2.token.c_str() ) );
        token_value = value1;
        token_value.isfloat = false;
	  } // else
	
    } // else if
  
    else if ( strcmp( exp.c_str(), "/=" ) == 0 ) {
  	  if ( value1.isfloat == true || value2.isfloat == true ) {
        value1.token = NumToString( atof( value1.token.c_str() ) / atof( value2.token.c_str() ) );
        token_value = value1;
        token_value.isfloat = true;
      } // if
    
      else {
        value1.token = NumToString( atoi( value1.token.c_str() ) / atoi( value2.token.c_str() ) );
        token_value = value1;
        token_value.isfloat = false;
	  } // else
	
    } // else if
  
    else if ( strcmp( exp.c_str(), "%=" ) == 0 ) {
      value1.token = NumToString( atoi( value1.token.c_str() ) % atoi( value2.token.c_str() ) );
      token_value = value1;
      token_value.isfloat = false;
	
    } // else if
  
    token_value.is_assign = true;
    SetValue( token_name, token_value ) ;
    
  } // else if
  
  
  else if ( m_shouldnot_operator_list.size() > 1 &&
            m_shouldnot_operator_list[ m_shouldnot_operator_list.size() - 1 ] == false &&
            Allow_before_m_shouldnot_operator_list() == true && 
			Allow_before_m_shouldnot_operator_list2() == true ) {
  	Token token_name = value1;
    Token token_value;
    While_Need_Data while_need_data;
  	while_need_data.is_operator = true;
  	while_need_data.operator_data.exp = exp;
  	while_need_data.operator_data.value1 = value1;
  	while_need_data.operator_data.value2 = value2;
  	m_While_Need_Data_list.push_back( while_need_data );
    
    GetValue( value1 );
    SetType( value1 );
    GetValue( value2 );
    SetType( value2 );
    if ( strcmp( exp.c_str(), "=" ) == 0 ) {
      value1 = value2;
      token_value = value1;
	} // if
    
    else if ( strcmp( exp.c_str(), "+=" ) == 0 ) {
  	  if ( strcmp( value1.type.c_str(), "STRING_CONSTANT" ) == 0 ) {
  	    value1.token = value1.token + value2.token ;
        token_value = value1;
        token_value.isfloat = false;
  	  
	  } // if
  	
  	  else if ( value1.isfloat == true || value2.isfloat == true ) {
        value1.token = NumToString( atof( value1.token.c_str() ) + atof( value2.token.c_str() ) );
        token_value = value1;
        token_value.isfloat = true;
      } // else if
    
      else {
        value1.token = NumToString( atoi( value1.token.c_str() ) + atoi( value2.token.c_str() ) );
        token_value = value1;
        token_value.isfloat = false;
	  } // else
    
    } // else if
  
    else if ( strcmp( exp.c_str(), "-=" ) == 0 ) {
  	  if ( value1.isfloat == true || value2.isfloat == true ) {
        value1.token = NumToString( atof( value1.token.c_str() ) - atof( value2.token.c_str() ) );
        token_value = value1;
        token_value.isfloat = true;
      } // if
    
      else {
        value1.token = NumToString( atoi( value1.token.c_str() ) - atoi( value2.token.c_str() ) );
        token_value = value1;
        token_value.isfloat = false;
	  } // else
	
    } // else if
  
    else if ( strcmp( exp.c_str(), "*=" ) == 0 ) {
  	  if ( value1.isfloat == true || value2.isfloat == true ) {
        value1.token = NumToString( atof( value1.token.c_str() ) * atof( value2.token.c_str() ) );
        token_value = value1;
        token_value.isfloat = true;
      } // if
    
      else {
        value1.token = NumToString( atoi( value1.token.c_str() ) * atoi( value2.token.c_str() ) );
        token_value = value1;
        token_value.isfloat = false;
	  } // else
	
    } // else if
  
    else if ( strcmp( exp.c_str(), "/=" ) == 0 ) {
  	  if ( value1.isfloat == true || value2.isfloat == true ) {
        value1.token = NumToString( atof( value1.token.c_str() ) / atof( value2.token.c_str() ) );
        token_value = value1;
        token_value.isfloat = true;
      } // if
    
      else {
        value1.token = NumToString( atoi( value1.token.c_str() ) / atoi( value2.token.c_str() ) );
        token_value = value1;
        token_value.isfloat = false;
	  } // else
	
    } // else if
  
    else if ( strcmp( exp.c_str(), "%=" ) == 0 ) {
      value1.token = NumToString( atoi( value1.token.c_str() ) % atoi( value2.token.c_str() ) );
      token_value = value1;
      token_value.isfloat = false;
	
    } // else if
  
    token_value.is_assign = true;
    SetValue( token_name, token_value ) ;
    
  } // else if
  
  
} // Project::AssignOperator()

// when if not happen, do ++i
// when if  happen, but can do, do ++i
// define data do ++i
// and getvalue to token
void Project::Do_First_MM( Token & token ) {
  	
  for ( int j = 0; j < m_define_table.size() && Allow_before_m_shouldnot_operator_list2() == true ; j++ ) {
  	if ( strcmp( token.token.c_str(), m_define_table[j].token_name.token.c_str() ) == 0 &&
		 m_define_table[j].value.is_arrary == false ) {
  	  if ( m_define_table[j].value.isfloat == true ) {
  	  	m_define_table[j].value.token = NumToString( atof( m_define_table[j].value.token.c_str() ) - 1 );
	  } // if
      	  
      else if ( m_define_table[j].value.isfloat == false ) {
      	m_define_table[j].value.token = NumToString( atoi( m_define_table[j].value.token.c_str() ) - 1 );
	  } // else if
		
	  GetValue( token );
	  SetType( token );
		
	} // if
	
	else if ( strcmp( token.token.c_str(), m_define_table[j].token_name.token.c_str() ) == 0 &&
		      m_define_table[j].value.is_arrary == true ) {
	  if ( m_define_table[j].value.isfloat == true ) {
  	  	// m_define_table[j].value.token = NumToString( atof( m_define_table[j].value.token.c_str() ) + 1 );
  	  	m_define_table[j].value.arrary_data[ atoi( token.select_arrary_num.c_str() ) ].token = 
  	  	NumToString( atof( m_define_table[j].value.
		arrary_data[ atoi( token.select_arrary_num.c_str() ) ].token.c_str() ) - 1 ) ;
	  } // if
      	  
      else if ( m_define_table[j].value.isfloat == false ) {
      	// m_define_table[j].value.token = NumToString( atoi( m_define_table[j].value.token.c_str() ) + 1 );
      	m_define_table[j].value.arrary_data[ atoi( token.select_arrary_num.c_str() ) ].token = 
  	  	NumToString( atoi( m_define_table[j].value.
		arrary_data[ atoi( token.select_arrary_num.c_str() ) ].token.c_str() ) - 1 ) ;
      	
	  } // else if
	  
	  GetValue( token );
	  SetType( token );
	  
	} // else if
	  
  } // for
	
  
  
} // Project::Do_First_MM()

// when if not happen, do --i
// when if  happen, but can do, do --i
// define data do --i
// and getvalue to token
void Project::Do_First_PP( Token & token ) {
  for ( int j = 0; j < m_define_table.size() && Allow_before_m_shouldnot_operator_list2() == true ; j++ ) {
  	if ( strcmp( token.token.c_str(), m_define_table[j].token_name.token.c_str() ) == 0 &&
		 m_define_table[j].value.is_arrary == true ) {
  	  if ( m_define_table[j].value.isfloat == true ) {
  	  	// m_define_table[j].value.token = NumToString( atof( m_define_table[j].value.token.c_str() ) + 1 );
  	  	m_define_table[j].value.arrary_data[ atoi( token.select_arrary_num.c_str() ) ].token = 
  	  	NumToString( atof( m_define_table[j].value.
		arrary_data[ atoi( token.select_arrary_num.c_str() ) ].token.c_str() ) + 1 ) ;
	  } // if
      	  
      else if ( m_define_table[j].value.isfloat == false ) {
      	// m_define_table[j].value.token = NumToString( atoi( m_define_table[j].value.token.c_str() ) + 1 );
      	m_define_table[j].value.arrary_data[ atoi( token.select_arrary_num.c_str() ) ].token = 
  	  	NumToString( atoi( m_define_table[j].value.
		arrary_data[ atoi( token.select_arrary_num.c_str() ) ].token.c_str() ) + 1 ) ;
      	
	  } // else if
	  
	  GetValue( token );
	  SetType( token );
	  // token = m_define_table[j].value.arrary_data[ atoi( token.select_arrary_num.c_str() ) ];
		
	} // if
	
	else if ( strcmp( token.token.c_str(), m_define_table[j].token_name.token.c_str() ) == 0 &&
		      m_define_table[j].value.is_arrary == false ) {
  	  if ( m_define_table[j].value.isfloat == true ) {
  	    m_define_table[j].value.token = NumToString( atof( m_define_table[j].value.token.c_str() ) + 1 );
	  } // if
      	  
      else if ( m_define_table[j].value.isfloat == false ) {
      	m_define_table[j].value.token = NumToString( atoi( m_define_table[j].value.token.c_str() ) + 1 );
	  } // else if
		
	  GetValue( token );
	  SetType( token );
	  // token = m_define_table[j].value;
		
	} // else if
	  
  } // for
	
  
  
} // Project::Do_First_PP()


// when if not happen, do i++
// when if  happen, but can do, do i++
// define data do i++
// and not getvalue to token
// first find data for local_table, and then find define_table
// when get data in local_table,not do find define_table
void Project::Do_Last_PP( Token token ) {
  bool is_get = false;
  for ( int j = 0; j < m_localData_table.size() && Allow_before_m_shouldnot_operator_list2() == true &&
        is_get == false ; j++ ) {
  	if ( strcmp( token.token.c_str(), m_localData_table[j].token_name.token.c_str() ) == 0 &&
		 m_localData_table[j].value.is_arrary == true ) {
	  is_get = true;
  	  if ( m_localData_table[j].value.isfloat == true ) {
  	  	// m_define_table[j].value.token = NumToString( atof( m_define_table[j].value.token.c_str() ) + 1 );
  	  	m_localData_table[j].value.arrary_data[ atoi( token.select_arrary_num.c_str() ) ].token = 
  	  	NumToString( atof( m_localData_table[j].value.
		arrary_data[ atoi( token.select_arrary_num.c_str() ) ].token.c_str() ) + 1 ) ;
	  } // if
      	  
      else if ( m_localData_table[j].value.isfloat == false ) {
      	// m_define_table[j].value.token = NumToString( atoi( m_define_table[j].value.token.c_str() ) + 1 );
      	m_localData_table[j].value.arrary_data[ atoi( token.select_arrary_num.c_str() ) ].token = 
  	  	NumToString( atoi( m_localData_table[j].value.
		arrary_data[ atoi( token.select_arrary_num.c_str() ) ].token.c_str() ) + 1 ) ;
      	
	  } // else if
	  
	  // token = m_define_table[j].value.arrary_data[ atoi( token.select_arrary_num.c_str() ) ];
		
	} // if
	
	else if ( strcmp( token.token.c_str(), m_localData_table[j].token_name.token.c_str() ) == 0 &&
		      m_localData_table[j].value.is_arrary == false ) {
	  is_get = true;
  	  if ( m_localData_table[j].value.isfloat == true ) {
  	  	m_localData_table[j].value.
		token = NumToString( atof( m_localData_table[j].value.token.c_str() ) + 1 );
	  } // if
      	  
      else if ( m_localData_table[j].value.isfloat == false ) {
      	m_localData_table[j].value.
		token = NumToString( atoi( m_localData_table[j].value.token.c_str() ) + 1 );
	  } // else if
		
	  // token = m_define_table[j].value;
		
	} // else if
	  
  } // for
  
  
  
  for ( int j = 0; j < m_define_table.size() && Allow_before_m_shouldnot_operator_list2() == true &&
        is_get == false ; j++ ) {
  	if ( strcmp( token.token.c_str(), m_define_table[j].token_name.token.c_str() ) == 0 &&
		 m_define_table[j].value.is_arrary == true ) {
  	  if ( m_define_table[j].value.isfloat == true ) {
  	  	// m_define_table[j].value.token = NumToString( atof( m_define_table[j].value.token.c_str() ) + 1 );
  	  	m_define_table[j].value.arrary_data[ atoi( token.select_arrary_num.c_str() ) ].token = 
  	  	NumToString( atof( m_define_table[j].value.
		arrary_data[ atoi( token.select_arrary_num.c_str() ) ].token.c_str() ) + 1 ) ;
	  } // if
      	  
      else if ( m_define_table[j].value.isfloat == false ) {
      	// m_define_table[j].value.token = NumToString( atoi( m_define_table[j].value.token.c_str() ) + 1 );
      	m_define_table[j].value.arrary_data[ atoi( token.select_arrary_num.c_str() ) ].token = 
  	  	NumToString( atoi( m_define_table[j].value.
		arrary_data[ atoi( token.select_arrary_num.c_str() ) ].token.c_str() ) + 1 ) ;
      	
	  } // else if
	  
	  // token = m_define_table[j].value.arrary_data[ atoi( token.select_arrary_num.c_str() ) ];
		
	} // if
	
	else if ( strcmp( token.token.c_str(), m_define_table[j].token_name.token.c_str() ) == 0 &&
		      m_define_table[j].value.is_arrary == false ) {
  	  if ( m_define_table[j].value.isfloat == true ) {
  	  	m_define_table[j].value.token = NumToString( atof( m_define_table[j].value.token.c_str() ) + 1 );
	  } // if
      	  
      else if ( m_define_table[j].value.isfloat == false ) {
      	m_define_table[j].value.token = NumToString( atoi( m_define_table[j].value.token.c_str() ) + 1 );
	  } // else if
		
	  // token = m_define_table[j].value;
		
	} // else if
	  
  } // for
	
  
  
} // Project::Do_Last_PP()

// when if not happen, do i--
// when if  happen, but can do, do i++
// define data do i--
// and not getvalue to token
// first find data for local_table, and then find define_table
// when get data in local_table,not do find define_table
void Project::Do_Last_MM( Token token ) {
  bool is_get = false;
  for ( int j = 0; j < m_localData_table.size() && 
        Allow_before_m_shouldnot_operator_list2() == true ; j++ ) {
  	if ( strcmp( token.token.c_str(), m_localData_table[j].token_name.token.c_str() ) == 0 &&
		 m_localData_table[j].value.is_arrary == false ) {
	  is_get = true;
  	  if ( m_localData_table[j].value.isfloat == true ) {
  	  	m_localData_table[j].value.
		token = NumToString( atof( m_localData_table[j].value.token.c_str() ) - 1 );
	  } // if
      	  
      else if ( m_localData_table[j].value.isfloat == false ) {
      	m_localData_table[j].value.
		token = NumToString( atoi( m_localData_table[j].value.token.c_str() ) - 1 );
	  } // else if
		
		
	} // if
	
	else if ( strcmp( token.token.c_str(), m_localData_table[j].token_name.token.c_str() ) == 0 &&
		      m_localData_table[j].value.is_arrary == true ) {
	  is_get = true;
	  if ( m_localData_table[j].value.isfloat == true ) {
  	  	// m_define_table[j].value.token = NumToString( atof( m_define_table[j].value.token.c_str() ) + 1 );
  	  	m_localData_table[j].value.arrary_data[ atoi( token.select_arrary_num.c_str() ) ].token = 
  	  	NumToString( atof( m_localData_table[j].value.
		arrary_data[ atoi( token.select_arrary_num.c_str() ) ].token.c_str() ) - 1 ) ;
	  } // if
      	  
      else if ( m_localData_table[j].value.isfloat == false ) {
      	// m_define_table[j].value.token = NumToString( atoi( m_define_table[j].value.token.c_str() ) + 1 );
      	m_localData_table[j].value.arrary_data[ atoi( token.select_arrary_num.c_str() ) ].token = 
  	  	NumToString( atoi( m_localData_table[j].value.
		arrary_data[ atoi( token.select_arrary_num.c_str() ) ].token.c_str() ) - 1 ) ;
      	
	  } // else if
	  
	  
	} // else if
	  
  } // for
  
  
  
  for ( int j = 0; j < m_define_table.size() && Allow_before_m_shouldnot_operator_list2() == true &&
        is_get == false ; j++ ) {
  	if ( strcmp( token.token.c_str(), m_define_table[j].token_name.token.c_str() ) == 0 &&
		 m_define_table[j].value.is_arrary == false ) {
  	  if ( m_define_table[j].value.isfloat == true ) {
  	  	m_define_table[j].value.token = NumToString( atof( m_define_table[j].value.token.c_str() ) - 1 );
	  } // if
      	  
      else if ( m_define_table[j].value.isfloat == false ) {
      	m_define_table[j].value.token = NumToString( atoi( m_define_table[j].value.token.c_str() ) - 1 );
	  } // else if
		
		
	} // if
	
	else if ( strcmp( token.token.c_str(), m_define_table[j].token_name.token.c_str() ) == 0 &&
		      m_define_table[j].value.is_arrary == true ) {
	  if ( m_define_table[j].value.isfloat == true ) {
  	  	// m_define_table[j].value.token = NumToString( atof( m_define_table[j].value.token.c_str() ) + 1 );
  	  	m_define_table[j].value.arrary_data[ atoi( token.select_arrary_num.c_str() ) ].token = 
  	  	NumToString( atof( m_define_table[j].value.
		arrary_data[ atoi( token.select_arrary_num.c_str() ) ].token.c_str() ) - 1 ) ;
	  } // if
      	  
      else if ( m_define_table[j].value.isfloat == false ) {
      	// m_define_table[j].value.token = NumToString( atoi( m_define_table[j].value.token.c_str() ) + 1 );
      	m_define_table[j].value.arrary_data[ atoi( token.select_arrary_num.c_str() ) ].token = 
  	  	NumToString( atoi( m_define_table[j].value.
		arrary_data[ atoi( token.select_arrary_num.c_str() ) ].token.c_str() ) - 1 ) ;
      	
	  } // else if
	  
	  
	} // else if
	  
  } // for
  
} // Project::Do_Last_MM()


// when token have sign
// doing sign operation
void Project::Sign_Value( Token & value, Token & sign ) {
  double num = 0;
  if ( strcmp( sign.token.c_str(), "+" ) == 0 ) {
  	;
  } // if
  
  else if ( strcmp( sign.token.c_str(), "-" ) == 0 ) {
  	if ( value.isfloat == true )
  	  value.token = NumToString( atof( value.token.c_str() ) * -1 );
  	else value.token = NumToString( atoi( value.token.c_str() ) * -1 );
  	
  } // else if
  
  else if ( strcmp( sign.token.c_str(), "!" ) == 0 ) {
  	if ( strcmp( value.token.c_str(), "true" ) == 0 ) {
  	  value.token = "false";
	} // if
	
	else if ( strcmp( value.token.c_str(), "false" ) == 0 ) {
  	  value.token = "true";
	} // if
	
	value.type = "BOOL_CONSTANT";
  } // else if
  
  
} // Project::Sign_Value()

// when if not happen, do 
// when if  happen, but can do, do 
// do all operation, like:+,-,>,>=,....
// GetValue, SetType
void Project::Operator( Token & value1, Token & value2, string exp ) {
  if ( m_shouldnot_operator_list.size() == 0 &&
       Allow_before_m_shouldnot_operator_list2() == true ) {
  	if ( m_is_while == true ) {
  	  While_Need_Data while_need_data;
  	  while_need_data.is_operator = true;
  	  while_need_data.operator_data.exp = exp;
  	  while_need_data.operator_data.value1 = value1;
  	  while_need_data.operator_data.value2 = value2;
  	  m_While_Need_Data_list.push_back( while_need_data );
	} // if
	
  	GetValue( value1 );
    GetValue( value2 );
    SetType( value1 );
    SetType( value2 );
    if ( strcmp( exp.c_str(), "+" ) == 0 && 
         strcmp( value1.type.c_str(), "STRING_CONSTANT" ) == 0 ) {
	
	  value1.token = value1.token + value2.token;
  	
    } // if
  
    else if ( strcmp( exp.c_str(), "+" ) == 0 ) {
  	  if ( value1.isfloat == false && value2.isfloat == false ) {
  	    int num;
        num = atoi( value1.token.c_str() ) + 
	    atoi( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";
	  } // if
	
	  else {
	    double num;
        num = atof( value1.token.c_str() ) + 
	    atof( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";	
        value1.isfloat = true;
	  } // else

    } // else if
  
    else if ( strcmp( exp.c_str(), "-" ) == 0 ) {
  	  if ( value1.isfloat == false && value2.isfloat == false ) {
  	    int num;
        num = atoi( value1.token.c_str() ) -
	    atoi( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";
	  } // if
  	
  	  else {
  	    double num;
        num = atof( value1.token.c_str() ) - 
	    atof( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";	
        value1.isfloat = true;
	  } // else

    } // else if
  
    else if ( strcmp( exp.c_str(), "*" ) == 0 ) {
  	  if ( value1.isfloat == false && value2.isfloat == false ) {
  	    int num;
        num = atoi( value1.token.c_str() ) *
	    atoi( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";
	  } // if
  	
  	  else {
  	    double num;
        num = atof( value1.token.c_str() ) * 
	    atof( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";	
        value1.isfloat = true;
	  } // else
	
    } // else if
  
    else if ( strcmp( exp.c_str(), "/" ) == 0 ) {
  	  if ( value1.isfloat == false && value2.isfloat == false ) {
  	    int num;
        num = atoi( value1.token.c_str() ) /
	    atoi( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";
	  } // if
  	
  	  else {
  	    double num;
        num = atof( value1.token.c_str() ) / 
	    atof( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";	
        value1.isfloat = true;
	  } // else
	
    } // else if
  
    else if ( strcmp( exp.c_str(), "%" ) == 0 ) {
      int num;
      num = atoi( value1.token.c_str() ) % atoi( value2.token.c_str() );
      value1.token = NumToString( num );
      value1.type = "NUM_CONSTANT";
    } // else if
  
    else if ( strcmp( exp.c_str(), "<<" ) == 0 ) {
  	  if ( value1.isfloat == false && value2.isfloat == false ) {
  	    int num;
        // num = 1;
        // for ( int i = 0; i < atoi( value2.token.c_str() ) ; i++ ) {
        //  num = num * 2;
	    // } // for
	
	    GetValue( value1 );
        num = atoi( value1.token.c_str() )  << atoi( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";
	  } // if
  	
  	  else {
  	    int num;
        // num = 1;
        // for ( int i = 0; i < atoi( value2.token.c_str() ) ; i++ ) {
        //  num = num * 2;
	    // } // for
	
	    GetValue( value1 );
	    num = atoi( value1.token.c_str() )  <<  atoi( value2.token.c_str() );
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";
  	    value1.isfloat = false;
	  } // else
	
	  // SetValue( value1.initial_data[0], value1 ) ;
  	
    } // else if
  
    else if ( strcmp( exp.c_str(), ">>" ) == 0 ) {
  	  if ( value1.isfloat == false && value2.isfloat == false ) {
  	    int num;
        // num = 1;
        // for ( int i = 0; i < atoi( value2.token.c_str() ) ; i++ ) {
        //  num = num * 2;
	    // } // for
	
	    GetValue( value1 );
        num = atoi( value1.token.c_str() )  >> atoi( value2.token.c_str() );
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";
	  } // if
  	
      else {
        int num;
        // num = 1;
        // for ( int i = 0; i < atoi( value2.token.c_str() ) ; i++ ) {
        //  num = num * 2;
	    // } // for
	
	    GetValue( value1 );
        num = atoi( value1.token.c_str() )  >> atoi( value2.token.c_str() );
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";
        value1.isfloat = false;
	  } // else
	
      // SetValue( value1.initial_data[0], value1 ) ;
    
    } // else if
  
    else if ( strcmp( exp.c_str(), "&&" ) == 0 ) {
      Relation( value1, value2, "&&" );
    } // else if
  
    else if ( strcmp( exp.c_str(), "||" ) == 0 ) {
      Relation( value1, value2, "||" );
    } // else if
  
    else if ( strcmp( exp.c_str(), "<" ) == 0 ) {
      Relation( value1, value2, "<" );
    } // else if
  
    else if ( strcmp( exp.c_str(), ">" ) == 0 ) {
      Relation( value1, value2, ">" );
    } // else if
  
    else if ( strcmp( exp.c_str(), "<=" ) == 0 ) {
      Relation( value1, value2, "<=" );
    } // else if
  
    else if ( strcmp( exp.c_str(), ">=" ) == 0 ) {
      Relation( value1, value2, ">=" );
    } // else if
  
    else if ( strcmp( exp.c_str(), "==" ) == 0 ) {
      Relation( value1, value2, "==" );
    } // else if
  
    else if ( strcmp( exp.c_str(), "!=" ) == 0 ) {
      Relation( value1, value2, "!=" );
    } // else if
    
  } // if
	
	
	
  else if ( m_shouldnot_operator_list.size() == 1 && 
            m_shouldnot_operator_list[ m_shouldnot_operator_list.size() - 1 ] == false &&
            Allow_before_m_shouldnot_operator_list2() == true ) {
            	
    if ( m_is_while == true ) {
  	  While_Need_Data while_need_data;
  	  while_need_data.is_operator = true;
  	  while_need_data.operator_data.exp = exp;
  	  while_need_data.operator_data.value1 = value1;
  	  while_need_data.operator_data.value2 = value2;
  	  m_While_Need_Data_list.push_back( while_need_data );
	} // if
	
  	GetValue( value1 );
    GetValue( value2 );
    SetType( value1 );
    SetType( value2 );
    if ( strcmp( exp.c_str(), "+" ) == 0 && 
         strcmp( value1.type.c_str(), "STRING_CONSTANT" ) == 0 ) {
	
	  value1.token = value1.token + value2.token;
  	
    } // if
  
    else if ( strcmp( exp.c_str(), "+" ) == 0 ) {
  	  if ( value1.isfloat == false && value2.isfloat == false ) {
  	    int num;
        num = atoi( value1.token.c_str() ) + 
	    atoi( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";
	  } // if
	
	  else {
	    double num;
        num = atof( value1.token.c_str() ) + 
	    atof( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";	
        value1.isfloat = true;
	  } // else

    } // else if
  
    else if ( strcmp( exp.c_str(), "-" ) == 0 ) {
  	  if ( value1.isfloat == false && value2.isfloat == false ) {
  	    int num;
        num = atoi( value1.token.c_str() ) -
	    atoi( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";
	  } // if
  	
  	  else {
  	    double num;
        num = atof( value1.token.c_str() ) - 
	    atof( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";	
        value1.isfloat = true;
	  } // else

    } // else if
  
    else if ( strcmp( exp.c_str(), "*" ) == 0 ) {
  	  if ( value1.isfloat == false && value2.isfloat == false ) {
  	    int num;
        num = atoi( value1.token.c_str() ) *
	    atoi( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";
	  } // if
  	
  	  else {
  	    double num;
        num = atof( value1.token.c_str() ) * 
	    atof( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";	
        value1.isfloat = true;
	  } // else
	
    } // else if
  
    else if ( strcmp( exp.c_str(), "/" ) == 0 ) {
  	  if ( value1.isfloat == false && value2.isfloat == false ) {
  	    int num;
        num = atoi( value1.token.c_str() ) /
	    atoi( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";
	  } // if
  	
  	  else {
  	    double num;
        num = atof( value1.token.c_str() ) / 
	    atof( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";	
        value1.isfloat = true;
	  } // else
	
    } // else if
  
    else if ( strcmp( exp.c_str(), "%" ) == 0 ) {
      int num;
      num = atoi( value1.token.c_str() ) % atoi( value2.token.c_str() );
      value1.token = NumToString( num );
      value1.type = "NUM_CONSTANT";
    } // else if
  
    else if ( strcmp( exp.c_str(), "<<" ) == 0 ) {
  	  if ( value1.isfloat == false && value2.isfloat == false ) {
  	    int num;
        // num = 1;
        // for ( int i = 0; i < atoi( value2.token.c_str() ) ; i++ ) {
        //  num = num * 2;
	    // } // for
	
	    GetValue( value1 );
        num = atoi( value1.token.c_str() )  << atoi( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";
	  } // if
  	
  	  else {
  	    int num;
        // num = 1;
        // for ( int i = 0; i < atoi( value2.token.c_str() ) ; i++ ) {
        //  num = num * 2;
	    // } // for
	
	    GetValue( value1 );
	    num = atoi( value1.token.c_str() )  <<  atoi( value2.token.c_str() );
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";
  	    value1.isfloat = false;
	  } // else
	
	  // SetValue( value1.initial_data[0], value1 ) ;
  	
    } // else if
  
    else if ( strcmp( exp.c_str(), ">>" ) == 0 ) {
  	  if ( value1.isfloat == false && value2.isfloat == false ) {
  	    int num;
        // num = 1;
        // for ( int i = 0; i < atoi( value2.token.c_str() ) ; i++ ) {
        //  num = num * 2;
	    // } // for
	
	    GetValue( value1 );
        num = atoi( value1.token.c_str() )  >> atoi( value2.token.c_str() );
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";
	  } // if
  	
      else {
        int num;
        // num = 1;
        // for ( int i = 0; i < atoi( value2.token.c_str() ) ; i++ ) {
        //  num = num * 2;
	    // } // for
	
	    GetValue( value1 );
        num = atoi( value1.token.c_str() )  >> atoi( value2.token.c_str() );
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";
        value1.isfloat = false;
	  } // else
	
      // SetValue( value1.initial_data[0], value1 ) ;
    
    } // else if
  
    else if ( strcmp( exp.c_str(), "&&" ) == 0 ) {
      Relation( value1, value2, "&&" );
    } // else if
  
    else if ( strcmp( exp.c_str(), "||" ) == 0 ) {
      Relation( value1, value2, "||" );
    } // else if
  
    else if ( strcmp( exp.c_str(), "<" ) == 0 ) {
      Relation( value1, value2, "<" );
    } // else if
  
    else if ( strcmp( exp.c_str(), ">" ) == 0 ) {
      Relation( value1, value2, ">" );
    } // else if
  
    else if ( strcmp( exp.c_str(), "<=" ) == 0 ) {
      Relation( value1, value2, "<=" );
    } // else if
  
    else if ( strcmp( exp.c_str(), ">=" ) == 0 ) {
      Relation( value1, value2, ">=" );
    } // else if
  
    else if ( strcmp( exp.c_str(), "==" ) == 0 ) {
      Relation( value1, value2, "==" );
    } // else if
  
    else if ( strcmp( exp.c_str(), "!=" ) == 0 ) {
      Relation( value1, value2, "!=" );
    } // else if
    
  } // else if
  
  else if ( m_shouldnot_operator_list.size() > 1 &&
            m_shouldnot_operator_list[ m_shouldnot_operator_list.size() - 1 ] == false &&
            Allow_before_m_shouldnot_operator_list() == true && 
			Allow_before_m_shouldnot_operator_list2() == true ) {
            	
    if ( m_is_while == true ) {
  	  While_Need_Data while_need_data;
  	  while_need_data.is_operator = true;
  	  while_need_data.operator_data.exp = exp;
  	  while_need_data.operator_data.value1 = value1;
  	  while_need_data.operator_data.value2 = value2;
  	  m_While_Need_Data_list.push_back( while_need_data );
	} // if
	
  	GetValue( value1 );
    GetValue( value2 );
    SetType( value1 );
    SetType( value2 );
    if ( strcmp( exp.c_str(), "+" ) == 0 && 
         strcmp( value1.type.c_str(), "STRING_CONSTANT" ) == 0 ) {
	
	  value1.token = value1.token + value2.token;
  	
    } // if
  
    else if ( strcmp( exp.c_str(), "+" ) == 0 ) {
  	  if ( value1.isfloat == false && value2.isfloat == false ) {
  	    int num;
        num = atoi( value1.token.c_str() ) + 
	    atoi( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";
	  } // if
	
	  else {
	    double num;
        num = atof( value1.token.c_str() ) + 
	    atof( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";	
        value1.isfloat = true;
	  } // else

    } // else if
  
    else if ( strcmp( exp.c_str(), "-" ) == 0 ) {
  	  if ( value1.isfloat == false && value2.isfloat == false ) {
  	    int num;
        num = atoi( value1.token.c_str() ) -
	    atoi( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";
	  } // if
  	
  	  else {
  	    double num;
        num = atof( value1.token.c_str() ) - 
	    atof( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";	
        value1.isfloat = true;
	  } // else

    } // else if
  
    else if ( strcmp( exp.c_str(), "*" ) == 0 ) {
  	  if ( value1.isfloat == false && value2.isfloat == false ) {
  	    int num;
        num = atoi( value1.token.c_str() ) *
	    atoi( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";
	  } // if
  	
  	  else {
  	    double num;
        num = atof( value1.token.c_str() ) * 
	    atof( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";	
        value1.isfloat = true;
	  } // else
	
    } // else if
  
    else if ( strcmp( exp.c_str(), "/" ) == 0 ) {
  	  if ( value1.isfloat == false && value2.isfloat == false ) {
  	    int num;
        num = atoi( value1.token.c_str() ) /
	    atoi( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";
	  } // if
  	
  	  else {
  	    double num;
        num = atof( value1.token.c_str() ) / 
	    atof( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";	
        value1.isfloat = true;
	  } // else
	
    } // else if
  
    else if ( strcmp( exp.c_str(), "%" ) == 0 ) {
      int num;
      num = atoi( value1.token.c_str() ) % atoi( value2.token.c_str() );
      value1.token = NumToString( num );
      value1.type = "NUM_CONSTANT";
    } // else if
  
    else if ( strcmp( exp.c_str(), "<<" ) == 0 ) {
  	  if ( value1.isfloat == false && value2.isfloat == false ) {
  	    int num;
        // num = 1;
        // for ( int i = 0; i < atoi( value2.token.c_str() ) ; i++ ) {
        //  num = num * 2;
	    // } // for
	
	    GetValue( value1 );
        num = atoi( value1.token.c_str() )  << atoi( value2.token.c_str() ) ;
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";
	  } // if
  	
  	  else {
  	    int num;
        // num = 1;
        // for ( int i = 0; i < atoi( value2.token.c_str() ) ; i++ ) {
        //  num = num * 2;
	    // } // for
	
	    GetValue( value1 );
	    num = atoi( value1.token.c_str() )  <<  atoi( value2.token.c_str() );
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";
  	    value1.isfloat = false;
	  } // else
	
	  // SetValue( value1.initial_data[0], value1 ) ;
  	
    } // else if
  
    else if ( strcmp( exp.c_str(), ">>" ) == 0 ) {
  	  if ( value1.isfloat == false && value2.isfloat == false ) {
  	    int num;
        // num = 1;
        // for ( int i = 0; i < atoi( value2.token.c_str() ) ; i++ ) {
        //  num = num * 2;
	    // } // for
	
	    GetValue( value1 );
        num = atoi( value1.token.c_str() )  >> atoi( value2.token.c_str() );
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";
	  } // if
  	
      else {
        int num;
        // num = 1;
        // for ( int i = 0; i < atoi( value2.token.c_str() ) ; i++ ) {
        //  num = num * 2;
	    // } // for
	
	    GetValue( value1 );
        num = atoi( value1.token.c_str() )  >> atoi( value2.token.c_str() );
        value1.token = NumToString( num );
        value1.type = "NUM_CONSTANT";
        value1.isfloat = false;
	  } // else
	
      // SetValue( value1.initial_data[0], value1 ) ;
    
    } // else if
  
    else if ( strcmp( exp.c_str(), "&&" ) == 0 ) {
      Relation( value1, value2, "&&" );
    } // else if
  
    else if ( strcmp( exp.c_str(), "||" ) == 0 ) {
      Relation( value1, value2, "||" );
    } // else if
  
    else if ( strcmp( exp.c_str(), "<" ) == 0 ) {
      Relation( value1, value2, "<" );
    } // else if
  
    else if ( strcmp( exp.c_str(), ">" ) == 0 ) {
      Relation( value1, value2, ">" );
    } // else if
  
    else if ( strcmp( exp.c_str(), "<=" ) == 0 ) {
      Relation( value1, value2, "<=" );
    } // else if
  
    else if ( strcmp( exp.c_str(), ">=" ) == 0 ) {
      Relation( value1, value2, ">=" );
    } // else if
  
    else if ( strcmp( exp.c_str(), "==" ) == 0 ) {
      Relation( value1, value2, "==" );
    } // else if
  
    else if ( strcmp( exp.c_str(), "!=" ) == 0 ) {
      Relation( value1, value2, "!=" );
    } // else if
    
  } // else if

} // Project::Operator()

// do compare operation
void Project::Relation( Token & value1, Token & value2, string exp ) {
  GetValue( value1 );
  GetValue( value2 );
  if ( strcmp( exp.c_str(), "&&" ) == 0 ) {
  	if ( strcmp( value1.type.c_str(), "NUM_CONSTANT" ) == 0 ||
         strcmp( value2.type.c_str(), "NUM_CONSTANT" ) == 0 ) {
      value1.token = "false";
      value1.type = "BOOL_CONSTANT";
    } // if
  	
    else if ( strcmp( value1.type.c_str(), "BOOL_CONSTANT" ) == 0 &&
              strcmp( value2.type.c_str(), "BOOL_CONSTANT" ) == 0 ) {
      if ( strcmp( value1.token.c_str(), "true" ) == 0 &&
	       strcmp( value2.token.c_str(), "true" ) == 0 ) {
        value1.token = "true";
        value1.type = "BOOL_CONSTANT";
	  } // if
	  
	  else if ( strcmp( value1.token.c_str(), "false" ) == 0 ||
	            strcmp( value2.token.c_str(), "false" ) == 0 ) {
        value1.token = "false";
        value1.type = "BOOL_CONSTANT";
	  } // else if

	} // else if
    
  } // if
  
  
  else if ( strcmp( exp.c_str(), "||" ) == 0 ) {
  	if ( strcmp( value1.type.c_str(), "NUM_CONSTANT" ) == 0 &&
         strcmp( value2.type.c_str(), "NUM_CONSTANT" ) == 0 ) {
      value1.token = "false";
      value1.type = "BOOL_CONSTANT";
    } // if
  	
    else if ( strcmp( value1.type.c_str(), "BOOL_CONSTANT" ) == 0 &&
              strcmp( value2.type.c_str(), "BOOL_CONSTANT" ) == 0 ) {
      if ( strcmp( value1.token.c_str(), "true" ) == 0 ||
	       strcmp( value2.token.c_str(), "true" ) == 0 ) {
        value1.token = "true";
        value1.type = "BOOL_CONSTANT";
	  } // if
	  
	  else if ( strcmp( value1.token.c_str(), "false" ) == 0 &&
	            strcmp( value2.token.c_str(), "false" ) == 0 ) {
        value1.token = "false";
        value1.type = "BOOL_CONSTANT";
	  } // else if

	} // else if
	
	else if ( strcmp( value1.type.c_str(), "NUM_CONSTANT" ) == 0 &&
              strcmp( value2.type.c_str(), "BOOL_CONSTANT" ) == 0 ) {
      if ( strcmp( value2.token.c_str(), "true" ) == 0 ) {
      	value1.token = "true";
        value1.type = "BOOL_CONSTANT";
	  } // if
	  
	  else {
	    value1.token = "false";
        value1.type = "BOOL_CONSTANT";	
	  } // else
      
    } // else if
	
    
    else if ( strcmp( value1.type.c_str(), "BOOL_CONSTANT" ) == 0 &&
              strcmp( value2.type.c_str(), "NUM_CONSTANT" ) == 0 ) {
      if ( strcmp( value1.token.c_str(), "true" ) == 0 ) {
      	value1.token = "true";
        value1.type = "BOOL_CONSTANT";
	  } // if
	  
	  else {
	    value1.token = "false";
        value1.type = "BOOL_CONSTANT";	
	  } // else
      
    } // else if
    
  } // else if
  
  
  else if ( strcmp( exp.c_str(), ">" ) == 0 ) {
  	if ( strcmp( value1.type.c_str(), "NUM_CONSTANT" ) == 0 &&
         strcmp( value2.type.c_str(), "NUM_CONSTANT" ) == 0 ) {
      if ( atof( value1.token.c_str() ) > atof( value2.token.c_str() ) ) {
      	value1.token = "true";
        value1.type = "BOOL_CONSTANT";
	  } // if
	  
	  else {
	    value1.token = "false";
        value1.type = "BOOL_CONSTANT";
	  } // else
      
    } // if
  	
  	else {
  	  if ( value1.token > value2.token ) {
      	value1.token = "true";
        value1.type = "BOOL_CONSTANT";
	  } // if
	  
	  else {
	    value1.token = "false";
        value1.type = "BOOL_CONSTANT";
	  } // else
	  
	} // else 
    
  } // else if
  
  else if ( strcmp( exp.c_str(), "<" ) == 0 ) {
  	if ( strcmp( value1.type.c_str(), "NUM_CONSTANT" ) == 0 &&
         strcmp( value2.type.c_str(), "NUM_CONSTANT" ) == 0 ) {
      if ( atof( value1.token.c_str() ) < atof( value2.token.c_str() ) ) {
      	value1.token = "true";
        value1.type = "BOOL_CONSTANT";
	  } // if
	  
	  else {
	    value1.token = "false";
        value1.type = "BOOL_CONSTANT";
	  } // else
      
    } // if
  	
  	else {
  	  if ( value1.token < value2.token ) {
      	value1.token = "true";
        value1.type = "BOOL_CONSTANT";
	  } // if
	  
	  else {
	    value1.token = "false";
        value1.type = "BOOL_CONSTANT";
	  } // else
	  
	} // else 
    
  } // else if
  
  else if ( strcmp( exp.c_str(), "<=" ) == 0 ) {
  	if ( strcmp( value1.type.c_str(), "NUM_CONSTANT" ) == 0 &&
         strcmp( value2.type.c_str(), "NUM_CONSTANT" ) == 0 ) {
      if ( atof( value1.token.c_str() ) <= atof( value2.token.c_str() ) ) {
      	value1.token = "true";
        value1.type = "BOOL_CONSTANT";
	  } // if
	  
	  else {
	    value1.token = "false";
        value1.type = "BOOL_CONSTANT";
	  } // else
      
    } // if
  	
  	else {
  	  if ( value1.token <= value2.token ) {
      	value1.token = "true";
        value1.type = "BOOL_CONSTANT";
	  } // if
	  
	  else {
	    value1.token = "false";
        value1.type = "BOOL_CONSTANT";
	  } // else
	  
	} // else 
    
  } // else if
  
  else if ( strcmp( exp.c_str(), ">=" ) == 0 ) {
  	if ( strcmp( value1.type.c_str(), "NUM_CONSTANT" ) == 0 &&
         strcmp( value2.type.c_str(), "NUM_CONSTANT" ) == 0 ) {
      if ( atof( value1.token.c_str() ) >= atof( value2.token.c_str() ) ) {
      	value1.token = "true";
        value1.type = "BOOL_CONSTANT";
	  } // if
	  
	  else {
	    value1.token = "false";
        value1.type = "BOOL_CONSTANT";
	  } // else
      
    } // if
  	
  	else {
  	  if ( value1.token >= value2.token ) {
      	value1.token = "true";
        value1.type = "BOOL_CONSTANT";
	  } // if
	  
	  else {
	    value1.token = "false";
        value1.type = "BOOL_CONSTANT";
	  } // else
	  
	} // else 
    
  } // else if
  
  else if ( strcmp( exp.c_str(), "==" ) == 0 ) {
  	if ( strcmp( value1.type.c_str(), "NUM_CONSTANT" ) == 0 &&
         strcmp( value2.type.c_str(), "NUM_CONSTANT" ) == 0 ) {
      if ( atof( value1.token.c_str() ) == atof( value2.token.c_str() ) ) {
      	value1.token = "true";
        value1.type = "BOOL_CONSTANT";
	  } // if
	  
	  else {
	    value1.token = "false";
        value1.type = "BOOL_CONSTANT";
	  } // else
      
    } // if
  	
  	else {
  	  if ( value1.token == value2.token ) {
      	value1.token = "true";
        value1.type = "BOOL_CONSTANT";
	  } // if
	  
	  else {
	    value1.token = "false";
        value1.type = "BOOL_CONSTANT";
	  } // else
	  
	} // else 
    
  } // else if
  
  else if ( strcmp( exp.c_str(), "!=" ) == 0 ) {
  	if ( strcmp( value1.type.c_str(), "NUM_CONSTANT" ) == 0 &&
         strcmp( value2.type.c_str(), "NUM_CONSTANT" ) == 0 ) {
      if ( atof( value1.token.c_str() ) != atof( value2.token.c_str() ) ) {
      	value1.token = "true";
        value1.type = "BOOL_CONSTANT";
	  } // if
	  
	  else {
	    value1.token = "false";
        value1.type = "BOOL_CONSTANT";
	  } // else
      
    } // if
  	
  	else {
  	  if ( value1.token != value2.token ) {
      	value1.token = "true";
        value1.type = "BOOL_CONSTANT";
	  } // if
	  
	  else {
	    value1.token = "false";
        value1.type = "BOOL_CONSTANT";
	  } // else
	  
	} // else 
    
  } // else if
  
} // Project::Relation()

// set type, NUM_CONSTANT,BOOL_CONSTANT,....
// remove bool, ' '
// remove string " " 
void Project::SetType( Token & token ) {
  bool is_num = true;
  bool is_bool = false;
  bool is_string = false;
  bool is_char = false;
  bool is_dot = false;
  bool next_line = false;
  string str = "";
  for ( int i = 0; i < token.token.size() ; i++ ) {
  	if ( token.token[i] == '.' ) is_dot = true;
  	if ( isdigit( token.token[i] ) == 0 &&
	     token.token[i] != '.' &&
		 token.token[i] != '-' ) {
  	  is_num = false;
	} // if
	
  } // for
  
  if ( is_num == true ) {
  	token.type = "NUM_CONSTANT";
  	if ( is_dot == true ) token.isfloat = true;
  	else token.isfloat = false;
  } // if
  
  if ( is_num == false ) {
  	if ( strcmp( token.token.c_str(), "true" ) == 0 ||
	     strcmp( token.token.c_str(), "false" ) == 0 ) {
  	  is_bool = true;
	} // if
  	
  	if ( is_bool == true ) token.type = "BOOL_CONSTANT";
  	if ( is_bool == false ) {
  	  if ( token.token[0] == '\"' && token.token[ token.token.size() - 1 ] == '\"' ) {
  	  	str = "";
  	  	for ( int i = 1; i < token.token.size() - 1 ; i++ ) {
  	  	  str = str + token.token[i];
		} // for
		
		token.token = str;
		str = "";
		for ( int i = 0; i < token.token.size() ; i++ ) {
		  if ( token.token[i] == '\\' ) {
		  	if ( i + 1 < token.token.size() ) {
		  	  if ( token.token[i + 1 ] == 'n' ) {
		  	    next_line = true;
			  } // if
				
			} // if
			  
		  } // if
			
		  if ( next_line == true ) {
			str = str + "\n";
			i = i + 1;
			next_line = false;
		  } // if
			
  	  	  else str = str + token.token[i];
  	  	    
		} // for
		
		token.token = str;  
  	    is_string = true;
	  } // if
	  
	  if ( is_string == true ) token.type = "STRING_CONSTANT";
	  if ( is_string == false ) {
	  	if ( token.token[0] == '\'' && token.token[ token.token.size() - 1 ] == '\'' ) {
	  	  str = "";
  	  	  for ( int i = 1; i < token.token.size() - 1 ; i++ ) {
  	  	    str = str + token.token[i];
		  } // for
		
		  token.token = str;
		  
		  
  	      is_char = true;
	    } // if
	  	
	  	if ( is_char == true ) token.type = "CHAR_CONSTANT";
	  } // if
  	  
	} // if
	
  } // if
  
  
} // Project::SetType()

// rest_of_maybe_additive_exp_value1 always cout, can do
void Project::CoutData( vector<Token> & tokenlist ) {  
  for ( int j = 0 ; j < tokenlist.size() && Allow_before_m_shouldnot_operator_list2() == true ; j++ ) {
  	if ( strcmp( tokenlist[j].token.c_str(), "\\n" ) == 0 ) {
  	  cout << "\n";
	} // if
	
  	else cout << tokenlist[j].token;
  	/*
  	for ( int i = 0; i < m_define_table.size() ; i++ ) {
      if ( strcmp( m_define_table[i].token_name.token.c_str(), tokenlist[j].token.c_str() ) == 0 ) {
        cout << m_define_table[i].value.token;
	  } // if
    
    } // for
    */
  } // for
  
  tokenlist.clear();
  
} // Project::CoutData()

// cintoken get token from m_input_buffer
void Project::CinData( vector<Token> tokenlist ) {
  bool finish = false;
  if ( Allow_before_m_shouldnot_operator_list2() == false && m_input_buffer.size() != 0 ) {
  	m_input_buffer.clear();
  } // if
  
  if ( m_input_buffer.size() < tokenlist.size() && Allow_before_m_shouldnot_operator_list2() == true ) {
    cout << "Run-time error : No input when cin '" << tokenlist[ m_input_buffer.size() ].token << "'!\n"; 
  } // if
  
  else if ( Allow_before_m_shouldnot_operator_list2() == true ) {
  	for ( int j = 0; j < tokenlist.size() && finish == false ; j++ ) {
  	  for ( int i = 0; i < m_define_table.size() && finish == false ; i++ ) {
        if ( strcmp( m_define_table[i].token_name.token.c_str(), tokenlist[j].token.c_str() ) == 0 ) {
          if ( m_input_buffer.size() == 0 ) {
          	cout << "Run-time error : No input when cin '" << tokenlist[j].token << "'!\n"; 
          	finish = true;
		  } // if
		  
		  else {
		  	m_define_table[i].value.token = m_input_buffer[0];
            m_input_buffer.erase( m_input_buffer.begin() );
		  } // else
          
	    } // if
    
      } // for
    
    } // for
    
  } // else if
	
  
} // Project::CinData()

// num to string (double)
string Project::NumToString( double num ) {
  string str;
  stringstream sstream;
  sstream << fixed << num;
  str = sstream.str();
  sstream.str( "" );
  return str;
} // Project::NumToString()

// num to string (int)
string Project::NumToString( int num ) {
  string str;
  stringstream sstream;
  sstream << fixed << num;
  str = sstream.str();
  sstream.str( "" );
  return str;
} // Project::NumToString()



// get value from m_localData_table or m_define_table
// gotten token's is_assign is true
void Project::GetValue( Token & token ) {
  Token tmp_token;
  bool finish = false;
  bool is_get = false;
  if ( strcmp( token.type.c_str(), "NUM_CONSTANT" ) != 0 &&
       strcmp( token.type.c_str(), "STRING_CONSTANT" ) != 0 &&
	   strcmp( token.type.c_str(), "BOOL_CONSTANT" ) != 0 &&
	   strcmp( token.type.c_str(), "CHAR_CONSTANT" ) != 0 ) {
	   	
	for ( int i = 0; i < m_localData_table.size() && m_compoundStatement == true && finish == false ; i++ ) {
      if ( strcmp( m_localData_table[i].token_name.token.c_str(), token.token.c_str() ) == 0 &&
	       m_localData_table[i].value.is_arrary == false && m_localData_table[i].value.is_assign == true ) {
	    is_get = true;
	    tmp_token.initial_data.push_back( token ) ;
        token = m_localData_table[i].value;
        token.initial_data = tmp_token.initial_data;
        finish = true;
	  } // if
	
	  else if ( strcmp( m_localData_table[i].token_name.token.c_str(), token.token.c_str() ) == 0 &&
	            m_localData_table[i].value.is_arrary == true && 
				m_localData_table[i].value.is_assign == true ) {
	    is_get = true;
	    tmp_token.initial_data.push_back( token ) ;
        token = m_localData_table[i].value.
	    arrary_data[ atoi( token.select_arrary_num.c_str() ) ];
	    token.initial_data = tmp_token.initial_data;
	    finish = true;
	  } // else if
    
    } // for
	   	
	   	
  	for ( int i = 0; i < m_define_table.size() && is_get == false && finish == false ; i++ ) {
      if ( strcmp( m_define_table[i].token_name.token.c_str(), token.token.c_str() ) == 0 &&
	       m_define_table[i].value.is_arrary == false ) {
	    tmp_token.initial_data.push_back( token ) ;
        token = m_define_table[i].value;
        token.initial_data = tmp_token.initial_data;
        finish = true;
	  } // if
	
	  else if ( strcmp( m_define_table[i].token_name.token.c_str(), token.token.c_str() ) == 0 &&
	            m_define_table[i].value.is_arrary == true ) {
	    tmp_token.initial_data.push_back( token ) ;
        token = m_define_table[i].value.
	    arrary_data[ atoi( token.select_arrary_num.c_str() ) ];
	    token.initial_data = tmp_token.initial_data;
	    finish = true;
	  } // else if
    
    } // for
    
    
  } // if
  
  if ( strcmp( token.type.c_str(), "NUM_CONSTANT" ) != 0 &&
       strcmp( token.type.c_str(), "STRING_CONSTANT" ) != 0 &&
	   strcmp( token.type.c_str(), "BOOL_CONSTANT" ) != 0 &&
	   strcmp( token.type.c_str(), "CHAR_CONSTANT" ) != 0 )
    SetType( token );
    
  
} // Project::GetValue()


// set value to m_localData_table or m_define_table
void Project::SetValue( Token & token_name, Token & token_value ) {
  double num = 0;
  int num2 = 0;
  bool is_set = false;
  if ( strcmp( token_value.type.c_str(), "NUM_CONSTANT" ) != 0 &&
       strcmp( token_value.type.c_str(), "BOOL_CONSTANT" ) != 0 &&
	   strcmp( token_value.type.c_str(), "STRING_CONSTANT" ) != 0 &&
	   strcmp( token_value.type.c_str(), "CHAR_CONSTANT" ) != 0 ) {
    GetValue( token_value );
	SetType( token_value );
  } // if
    
    
    
  for ( int i = 0; i < m_localData_table.size() && m_compoundStatement == true ; i++ ) {
    if ( strcmp( m_localData_table[i].token_name.token.c_str(), token_name.token.c_str() ) == 0 &&
	     m_localData_table[i].value.is_arrary == false ) {
	  is_set = true;
      if ( strcmp( token_value.sign.c_str(), "-" ) == 0 ) {
      	if ( token_value.isfloat == true )
      	  m_localData_table[i].value.token = NumToString( atof( token_value.token.c_str() ) * -1 );
      	else if ( token_value.isfloat == false )
      	  m_localData_table[i].value.token = NumToString( atoi( token_value.token.c_str() ) * -1 );
      	  
      	// m_define_table[i].value.token = NumToString( num );
      	m_localData_table[i].value.type = token_value.type;
	  } // if
	  
	  else if ( strcmp( token_value.sign.c_str(), "!" ) == 0 ) {
	  	if ( strcmp( token_value.token.c_str(), "true" ) == 0 ) {
	  	  token_value.token = "false";
		} // if
		
		else if ( strcmp( token_value.token.c_str(), "false" ) == 0 ) {
		  token_value.token = "true";
		} // else if
		
		m_localData_table[i].value = token_value;
	  } // else if
	  
	  else {
	  	m_localData_table[i].value = token_value;
	  } // else
	  
	} // if
	
	
    else if ( strcmp( m_localData_table[i].token_name.token.c_str(), token_name.token.c_str() ) == 0 &&
	          m_localData_table[i].value.is_arrary == true ) {
	  is_set = true;
      if ( strcmp( token_value.sign.c_str(), "-" ) == 0 ) {
      	if ( token_value.isfloat == true ) {
      	  m_localData_table[i].value.arrary_data[ atoi( token_name.select_arrary_num.c_str() ) ].
		  token = NumToString( atof( token_name.token.c_str() ) * -1 );
	    } // if
	    
      	else if ( token_value.isfloat == false ) {
      	  m_localData_table[i].value.arrary_data[ atoi( token_name.select_arrary_num.c_str() ) ].
		  token = NumToString( atoi( token_name.token.c_str() ) * -1 );
		} // else if
      	  
      	  
      	// m_define_table[i].value.token = NumToString( num );
      	m_localData_table[i].value.
		arrary_data[ atoi( token_name.select_arrary_num.c_str() ) ].type = token_value.type;
	  } // if
	  
	  else if ( strcmp( token_value.sign.c_str(), "!" ) == 0 ) {
	  	if ( strcmp( token_value.token.c_str(), "true" ) == 0 ) {
	  	  token_value.token = "false";
		} // if
		
		else if ( strcmp( token_value.token.c_str(), "false" ) == 0 ) {
		  token_value.token = "true";
		} // else if
		
		m_localData_table[i].value.arrary_data[ atoi( token_name.select_arrary_num.c_str() ) ] = token_value;
	  } // else if
	  
	  else {
	  	m_localData_table[i].value.arrary_data[ atoi( token_name.select_arrary_num.c_str() ) ] = token_value;
	  } // else
	  
	} // else if
    
    
  } // for
  	

  
  for ( int i = 0; i < m_define_table.size() && is_set == false ; i++ ) {
    if ( strcmp( m_define_table[i].token_name.token.c_str(), token_name.token.c_str() ) == 0 &&
	     m_define_table[i].value.is_arrary == false ) {
      if ( strcmp( token_value.sign.c_str(), "-" ) == 0 ) {
      	if ( token_value.isfloat == true )
      	  m_define_table[i].value.token = NumToString( atof( token_value.token.c_str() ) * -1 );
      	else if ( token_value.isfloat == false )
      	  m_define_table[i].value.token = NumToString( atoi( token_value.token.c_str() ) * -1 );
      	  
      	// m_define_table[i].value.token = NumToString( num );
      	m_define_table[i].value.type = token_value.type;
	  } // if
	  
	  else if ( strcmp( token_value.sign.c_str(), "!" ) == 0 ) {
	  	if ( strcmp( token_value.token.c_str(), "true" ) == 0 ) {
	  	  token_value.token = "false";
		} // if
		
		else if ( strcmp( token_value.token.c_str(), "false" ) == 0 ) {
		  token_value.token = "true";
		} // else if
		
		m_define_table[i].value = token_value;
	  } // else if
	  
	  else {
	  	m_define_table[i].value = token_value;
	  } // else
	  
	} // if
	
	
    else if ( strcmp( m_define_table[i].token_name.token.c_str(), token_name.token.c_str() ) == 0 &&
	          m_define_table[i].value.is_arrary == true ) {
      if ( strcmp( token_value.sign.c_str(), "-" ) == 0 ) {
      	if ( token_value.isfloat == true ) {
      	  m_define_table[i].value.arrary_data[ atoi( token_name.select_arrary_num.c_str() ) ].
		  token = NumToString( atof( token_name.token.c_str() ) * -1 );
	    } // if
	    
      	else if ( token_value.isfloat == false ) {
      	  m_define_table[i].value.arrary_data[ atoi( token_name.select_arrary_num.c_str() ) ].
		  token = NumToString( atoi( token_name.token.c_str() ) * -1 );
		} // else if
      	  
      	  
      	// m_define_table[i].value.token = NumToString( num );
      	m_define_table[i].value.
		arrary_data[ atoi( token_name.select_arrary_num.c_str() ) ].type = token_value.type;
	  } // if
	  
	  else if ( strcmp( token_value.sign.c_str(), "!" ) == 0 ) {
	  	if ( strcmp( token_value.token.c_str(), "true" ) == 0 ) {
	  	  token_value.token = "false";
		} // if
		
		else if ( strcmp( token_value.token.c_str(), "false" ) == 0 ) {
		  token_value.token = "true";
		} // else if
		
		m_define_table[i].value.arrary_data[ atoi( token_name.select_arrary_num.c_str() ) ] = token_value;
	  } // else if
	  
	  else {
	  	m_define_table[i].value.arrary_data[ atoi( token_name.select_arrary_num.c_str() ) ] = token_value;
	  } // else
	  
	} // else if
    
    
  } // for
  
} // Project::SetValue()

// show m_define_table all variables
void Project::ListAllVariables() {
  Value tmp_token;
  for ( int i = 0; i < m_define_table.size() ; i++ ) {
  	for ( int j = 0; j < m_define_table.size() - i - 1 ; j++ ) {
  	  if ( strcmp( m_define_table[j].token_name.token.
		   c_str(), m_define_table[j+1].token_name.token.c_str() ) > 0 ) {
  	  	tmp_token = m_define_table[j];
  	  	m_define_table[j] = m_define_table[j+1];
  	  	m_define_table[j+1] = tmp_token;
	  } // if
	  
	} // for
	
  } // for
  
  for ( int i = 0; i < m_define_table.size() ; i++ ) {
    cout << m_define_table[i].token_name.token << "\n";
  } // for
  
} // Project::ListAllVariables()

// show m_fuction_table all fuctions
void Project::ListAllFunctions() {
  Token tmp_token ;
  for ( int i = 0; i < m_fuction_table.size() ; i++ ) {
  	for ( int j = 0; j < m_fuction_table.size() - i - 1 ; j++ ) {
  	  if ( strcmp( m_fuction_table[j].token.c_str(), m_fuction_table[j+1].token.c_str() ) > 0 ) {
  	  	tmp_token = m_fuction_table[j];
  	  	m_fuction_table[j] = m_fuction_table[j+1];
  	  	m_fuction_table[j+1] = tmp_token;
	  } // if
	  
	} // for
	
  } // for
  
	
  for ( int i = 0; i < m_fuction_table.size() ; i++ ) {
  	if ( strcmp( m_fuction_table[i].token.c_str(), "Done" ) != 0 &&
	     strcmp( m_fuction_table[i].token.c_str(), "ListAllFunctions" ) != 0 &&
		 strcmp( m_fuction_table[i].token.c_str(), "ListAllVariables" ) != 0 &&
		 strcmp( m_fuction_table[i].token.c_str(), "ListFunction" ) != 0 &&
		 strcmp( m_fuction_table[i].token.c_str(), "ListVariable" ) != 0 &&
		 strcmp( m_fuction_table[i].token.c_str(), "cin" ) != 0 &&
		 strcmp( m_fuction_table[i].token.c_str(), "cout" ) != 0  ) {
  	  cout << m_fuction_table[i].token << "()\n";
	} // if
    
  } // for
  
} // Project::ListAllFunctions()

// show variable data,like: int a[2];
void Project::ListVariable() {
  string tmp_str = "";
  for ( int i = 0; i < m_define_table.size() ; i++ ) {
    tmp_str =  "\"" + m_define_table[i].token_name.token + "\"";
    if ( strcmp( m_select_funct.c_str(), tmp_str.c_str() ) == 0 ) {
      cout << m_define_table[i].token_name.function_data << "\n";
    } // if
    
  } // for
  
} // Project::ListVariable()

// show function data,like: int A(){int x;}
// cout << token.function_data
void Project::ListFunction() {
  string tmp_str = "";
  for ( int i = 0; i < m_fuction_table.size() ; i++ ) {
    tmp_str =  "\"" + m_fuction_table[i].token + "\"";
    if ( strcmp( m_select_funct.c_str(), tmp_str.c_str() ) == 0 ) {
      cout << m_fuction_table[i].function_data << "\n";
    } // if
    
  } // for
  
} // Project::ListFunction()

// deal with undefined_error
// do Is_User_Input, until Done();
void Project::Execute() {
  bool is_correct = true;
  Token token;
  while ( m_is_Done == false ) {
    Is_User_Input( is_correct );
    if ( m_undefined_ide == true ) {
      GetToken( token ) ;
      cout << "Line " << m_now_line << " :" << " undefined identifier : \'" << token.token << "\'\n";
      Skip_Line();
      m_is_peek = false;
      m_undefined_ide = false;
      m_now_line = 1;
    } // if
    
  } // while 
  
  
  
} // Project::Execute()

// push_back , cin,cout... to function table
void Project::Creat_define_table() {
  Token temp_token;
  temp_token.token = "";
  temp_token.token = temp_token.token + "cout";
  m_fuction_table.push_back( temp_token );
  temp_token.token = "";
  temp_token.token = temp_token.token + "Done";
  m_fuction_table.push_back( temp_token );
  temp_token.token = "";
  temp_token.token = temp_token.token + "cin";
  m_fuction_table.push_back( temp_token );
  temp_token.token = "";
  temp_token.token = temp_token.token + "ListAllFunctions";
  m_fuction_table.push_back( temp_token );
  temp_token.token = "";
  temp_token.token = temp_token.token + "ListFunction";
  m_fuction_table.push_back( temp_token );
  temp_token.token = "";
  temp_token.token = temp_token.token + "ListVariable";
  m_fuction_table.push_back( temp_token );
  temp_token.token = "";
  temp_token.token = temp_token.token + "ListAllVariables";
  m_fuction_table.push_back( temp_token );
} // Project::Creat_define_table()

// Get next token
// can't Get next token until do GetToken()
// when m_while_getExpression && m_while_getStatement happen
// save data to m_while_condition and m_while_statement
void Project::PeekToken() {
  if ( m_while_getExpression == true ) {
  	m_peek_token = m_while_condition[ m_expression_loc ];
  } // if
  
  else if ( m_while_getStatement == true ) {
  	m_peek_token = m_while_statement[ m_statement_loc ];
  } // else if
	
  else {
  	string type_name = "";
    Token temp_token;
    temp_token.is_million = false;
    string m_nowtoken = "";
    bool num = false;
    bool finish = false;
    bool is_function = false;
    if ( m_is_peek == false ) {
      // Skip_Whitespace() ;
      m_now_ch_from_string = cin.get() ;
      // if ( m_now_definition == true ) {
      //  if ( m_now_ch_from_string == '\n' )
      //    m_instruction_str = m_instruction_str + m_now_ch_from_string;
      // } // if
    
      // cout << m_now_ch_from_string << "\n";
      Skip_Whitespace() ;
      m_nowtoken = m_nowtoken + m_now_ch_from_string;
      // while ( finish == false && m_now_ch_from_string != EOF ) {
      // Constant num
      if ( isdigit( m_now_ch_from_string ) != 0 ||
           Is_for_Num( m_now_ch_from_string ) == true ) {
        // get NUM token
        Num( m_nowtoken ) ;
        if ( m_decimal_point == true ) {
          temp_token.isfloat = true;
        } // if
      
        else {
          temp_token.isfloat = false;
        } // else
      
        m_decimal_point = false;
        // add token to tokenlist
        temp_token.type = "CONSTANT";
        temp_token.token = m_nowtoken;
        m_tokenline.push_back( temp_token ) ;
      
      } // if
    
      // Sign
      // m_nowtoken = SIGN 
      else if ( Is_Sign( m_now_ch_from_string ) == true && cin.peek() != '+' && cin.peek() != '-' 
	            && cin.peek() != '=' ) {
        // isdigit( cin.peek() ) != 0
        m_nowtoken = "";
        m_nowtoken = m_nowtoken + m_now_ch_from_string;
        temp_token.type = "SIGN";
        temp_token.token = m_nowtoken;

      
      } // else if
    
      // Identifier
      else if ( Is_Letter( m_now_ch_from_string ) == true ) {
        // get IDENT token
        IDENT( m_nowtoken ) ;
      
        // definition type
        temp_token.token = m_nowtoken;
        Is_Definition( temp_token ) ;

      
      } // else if
    
      else if ( m_now_ch_from_string == '\'' ||
                m_now_ch_from_string == '\"' ) {
        if ( m_now_ch_from_string == '\'' ) {
          m_now_ch_from_string = cin.get();
          m_nowtoken = m_nowtoken + m_now_ch_from_string;
          while ( m_now_ch_from_string != '\'' ) {
            m_now_ch_from_string = cin.get();
            m_nowtoken = m_nowtoken + m_now_ch_from_string;
          } // while
        
        
        } // if
      
        else if ( m_now_ch_from_string == '\"' ) {
          m_now_ch_from_string = cin.get();
          m_nowtoken = m_nowtoken + m_now_ch_from_string;
          while ( m_now_ch_from_string != '\"' ) {
            m_now_ch_from_string = cin.get();
            m_nowtoken = m_nowtoken + m_now_ch_from_string;
          } // while
        
        } // else if
      
        temp_token.type = "CONSTANT";
        temp_token.token = m_nowtoken;

      } // else if
      
      //  Operator
      else if (  Is_symbol_for_token( m_nowtoken ) == true ) {
        if ( strcmp( m_nowtoken.c_str(), "{" ) == 0 )
          is_function = true;
        if ( strcmp( m_nowtoken.c_str(), ";" ) == 0 && 
             is_function == false ) {
          finish = true;
          m_is_has_semicolon = true;
        } // if
      
        else if ( strcmp( m_nowtoken.c_str(), "}" ) == 0 && 
                  is_function == true ) {
          finish = true;
          m_is_has_semicolon = true;
        } // else if
    
        // add token to tokenlist
        temp_token.type = "OPERATOR";
        temp_token.token = m_nowtoken;
        m_tokenline.push_back( temp_token ) ;
      
        if (  m_now_ch_from_string == ';' && is_function == false ) {
          if (  m_tokenline.size() != 0 ) {
            m_tokenline_list.push_back( m_tokenline ) ;
            m_tokenline.clear() ;
          } // if
        
        } // if
      
        else if ( m_now_ch_from_string == '}' && is_function == true ) {
          if (  m_tokenline.size() != 0 ) {
            m_tokenline_list.push_back( m_tokenline ) ;
            m_tokenline.clear() ;
          } // if
        
        } // else if
      
      
      } // else if
    
      else {
        m_unrecognized_exist = true;
        temp_token.token = temp_token.token + m_now_ch_from_string;
	  } // else
	
      m_peek_token = temp_token;

    
      m_is_peek = true;
      // cout << m_peek_token.token << "----" << "\n";
      // } // while
  

  
      if (  m_now_ch_from_string == EOF ) {
        m_IsEOF = true;
        // cout << "\n++++++++++++++aaaaaaaaaaa\n"; 
      } // if
    
    } // if
    
  } // else
  
  
  
  
} // Project::PeekToken()

// check char is it for Num 
bool Project::Is_for_Num( char ch ) {
  if (  ch == '.' && m_decimal_point == false ) {
    m_decimal_point = true;
    return true;
  } // if
    
  else if (  ch >= '0' && ch <= '9' ) return true;
  else return false;
  
} // Project::Is_for_Num()

// check char is it for IDE 
//  Determine whether it is char for IDENT 
bool Project::Is_for_IDENT( char ch ) {
  if (  Is_Letter( ch ) == true )
    return true;
  else if (  ch >= '0' && ch <= '9' ) return true;
  else if (  ch == '_' ) return true;
  else return false;
  
} // Project::Is_for_IDENT()

// check char is it for letter 
//  Determine first char whether it is English letter
bool Project::Is_Letter( char ch ) {
  if (  ch >= 'a' && ch <= 'z' )
    return true;
  else if (  ch >= 'A' && ch <= 'Z' ) return true;
  else {
    return false;
  } // else
  
} // Project::Is_Letter()

// check char is it for Sign 
//  Determine first char whether it is Sign
bool Project::Is_Sign( char ch ) {
  if (  ch == '+' || ch == '-' ) {
  	return true;
  } // if
   
  else return false;
  
} // Project::Is_Sign()

// Get a complete Num string
// consequent get char for Num until " " or "\n"
// and get to str 
void Project::Num( string  & str  ) {
  bool whitespace = false;
  // bool decimal_point = false;
  bool is_for_num = false;
  char check_ch = '\0';
  m_now_ch_from_string = cin.peek() ;
  if (  m_now_ch_from_string != EOF ) {
    if (  m_now_ch_from_string == ' ' ) whitespace = true;
    if (  whitespace == true ) is_for_num = true;
    else {
      // check next input 'char'
      is_for_num = Is_for_Num( m_now_ch_from_string ) ;
      if ( is_for_num == true ) m_now_ch_from_string = cin.get() ;
    } // else
    
    while ( m_now_ch_from_string != EOF  &&  whitespace == false && is_for_num == true ) { 
      str = str + m_now_ch_from_string;
      m_now_ch_from_string = cin.peek() ;
      if (  m_now_ch_from_string != EOF ) {
        if (  m_now_ch_from_string == ' ' ) whitespace = true;
        //  if next is whitespace,now is NUM,because now is digit char
        //  so must is NUM
        if (  whitespace == true ) is_for_num = true;
        else {
          is_for_num = Is_for_Num( m_now_ch_from_string ) ;
          if ( is_for_num == true ) {
            m_now_ch_from_string = cin.get();
          } // if
          
        } // else
        
      } // if

      
      
    } // while
    
        
    
  } // if
  
  else {
    is_for_num = true;
  } // else
  
  // if ( m_decimal_point == true ) {
  //    isfloat = true;
  // }
  // m_decimal_point = false;
  
  //  now not in final m_loc
  //  finaly, m_input_str[now_str_m_loc] is not for num or finish
  
    
} // Project::Num()

// Get a complete IDENT string
// consequent get char for IDENT until " " or "\n"
// and get to str 
void Project::IDENT( string  & str  ) {
  bool is_for_ident = false;
  bool m_is_quit_first = false;
  bool whitespace = false;
  bool decimal_point = false;
  char check_ch = '\0';
  m_now_ch_from_string = cin.peek() ;
  if (  m_now_ch_from_string != EOF ) {
    
    if (  m_now_ch_from_string == ' ' ) whitespace = true;
    if (  whitespace == true ) is_for_ident = true;
    else {
      // check next input 'char'
      is_for_ident = Is_for_IDENT( m_now_ch_from_string  ) ;
      if ( is_for_ident == true ) m_now_ch_from_string = cin.get() ;
    } // else
    
    while ( m_now_ch_from_string != EOF  &&  whitespace == false && 
            is_for_ident == true && m_is_quit_first == false ) 
    { 
      str = str + m_now_ch_from_string;
      m_now_ch_from_string = cin.peek() ;
      
      if (  m_now_ch_from_string != EOF ) {
        if (  m_now_ch_from_string == ' ' ) whitespace = true;
        //  if next is whitespace,now is NUM,because now is digit char
        //  so must is NUM
        if (  whitespace == true ) is_for_ident = true;
        else {
          is_for_ident = Is_for_IDENT( m_now_ch_from_string ) ;
          if ( is_for_ident == true ) {
            m_now_ch_from_string = cin.get();
          } // if
          
        } // else
        
      } // if
   
    } // while
    
  } // if
  
  else {
    is_for_ident = true;
  } // else
  
  
} // Project::IDENT()


// while white_space == true or // , skip it
// when get "\n", m_now_line++
void Project::Skip_Whitespace() {
  //  now is WhiteSpace
  bool white_space = false;
  bool is_comment = false;
  if ( m_now_ch_from_string == '/' ) {
    if ( cin.peek() == '/' ) {
      is_comment = true;
	  
    } // if
    
  } // if
  
  if ( m_now_ch_from_string == ' ' || m_now_ch_from_string == '\n' ) {
    white_space = true;
    if ( m_now_ch_from_string == '\n' ) {
      m_now_line++ ;
	} // if
    
    if (  m_tokenline.size() != 0 && m_now_ch_from_string == '\n' ) {
      m_tokenline_list.push_back( m_tokenline ) ;
      m_tokenline.clear() ;
    } // if
    
    else if ( m_tokenline.size() != 0 && m_now_ch_from_string == EOF ) {
      m_tokenline_list.push_back( m_tokenline ) ;
      m_tokenline.clear() ;
    } // else if
    
  } // if
  
  while ( is_comment == true 
          || white_space == true ) 
  {
    if ( is_comment == true ) {
      while ( m_now_ch_from_string != '\n' 
              && m_now_ch_from_string != EOF ) {
	    
        m_now_ch_from_string = cin.get();
        // if ( m_now_definition == true && m_now_ch_from_string == '\n' ) {
      	//  m_instruction_str = m_instruction_str + m_now_ch_from_string;
	    // } // if
	    
        if ( m_now_ch_from_string == '\n' ) {
          m_now_line++;
        } // if
        
      } // while
      
      is_comment = false;
      if ( m_now_ch_from_string == EOF ) {
        white_space = false;
      } // if
      
      else if ( m_now_ch_from_string == '\n' ) {
        white_space = true;
      } // else if
      
    } // if
    
    while ( white_space == true ) {
      m_now_ch_from_string = cin.get() ;
      // if ( m_now_definition == true ) {
      //  if ( m_now_ch_from_string == '\n' )
      //    m_instruction_str = m_instruction_str + m_now_ch_from_string;
      // } // if
      
      if ( m_now_ch_from_string == '\n' ) {
        m_now_line++;
      } // if
      
      if ( m_now_ch_from_string != ' ' && m_now_ch_from_string != '\n' ) {
        white_space = false;
      } // if
    
      if (  m_tokenline.size() != 0 && m_now_ch_from_string == '\n' ) {
        m_tokenline_list.push_back( m_tokenline ) ;
        m_tokenline.clear() ;
      } // if
      
      else if ( m_tokenline.size() != 0 && m_now_ch_from_string == EOF ) {
        m_tokenline_list.push_back( m_tokenline ) ;
        m_tokenline.clear() ;
      } // else if
    
    } // while
    
    if ( m_now_ch_from_string == '/' ) {
      if ( cin.peek() == '/' ) {
        is_comment = true;
      } // if
    
    } // if
    
  } // while
  


} // Project::Skip_Whitespace()

// do it when statement,definitin finish , skip "\n"
// like : int a ;"\n"  , get the "\n" back ;
void Project::Skip_final_line() {
  char ch;
  bool finish = false;
  ch = cin.peek(); 
  bool white_space = false;
  bool is_comment = false;
  if ( ch == '/' ) {
  	ch = cin.get();
    if ( cin.peek() == '/' ) {
      is_comment = true;
	  cin.get();
    } // if
    
    else cin.putback( ch ); 
    
  } // if
  
  else if ( ch == ' ' || ch == '\n' ) {
    white_space = true;
    if ( ch == '\n' ) {
      cin.get();
      finish = true;
	} // if
    
  } // if
  

  if ( is_comment == true ) {
    while ( ch != '\n' 
            && ch != EOF ) {
      ch = cin.get();
      if ( ch == '\n' ) finish = true;
      
    } // while
      
  } // if
    
  else if ( finish == false ) {
    while ( white_space == true && finish == false ) {
      ch = cin.get() ;
      if ( ch == '\n' ) finish = true;
      ch = cin.peek();
      if ( ch != ' ' && ch != '\n' && ch != '/' ) {
        white_space = false;
      } // if
        
      else if ( ch == '/' ) {
        ch = cin.get();
        if ( cin.peek() == '/' ) {
          is_comment = true;
	      cin.get();
	      while ( ch != '\n' 
                  && ch != EOF ) {
            ch = cin.get();
            if ( ch == '\n' ) finish = true;
            
          } // while
          
        } // if
    
        else {
          cin.putback( ch ); 
          white_space = false;
		} // else
          
	  } // else if
    
      else {
        white_space = true;
	  } // else 
		
    } // while
      
  } // else if
    
  
  
} // Project::Skip_final_line()

// abort error line
void Project::Skip_Line() {
  m_now_ch_from_string = cin.peek();
  while ( m_now_ch_from_string != '\n' && m_now_ch_from_string != EOF ) {
    m_now_ch_from_string = cin.get() ;
    // cout << "\n" << "!!! " << m_now_ch_from_string << " !!\n";
    m_now_ch_from_string = cin.peek();
  } // while
  
  if ( m_now_ch_from_string == '\n' || m_now_ch_from_string == EOF ) {
    m_now_ch_from_string = cin.get() ;
    if ( m_now_ch_from_string == EOF ) {
      m_IsEOF = true;
    } // if
    
  } // if
  
} // Project::Skip_Line()

// check is m_nowtoken symbol 
// and add char for symbol in  m_nowtoken, like: <=
bool Project::Is_symbol_for_token( string  & m_nowtoken ) {
  if ( m_now_ch_from_string == ';' || 
       m_now_ch_from_string == '(' || m_now_ch_from_string == ')' || m_now_ch_from_string == '[' ||
       m_now_ch_from_string == ']' || m_now_ch_from_string == '{' || m_now_ch_from_string == '}' || 
       m_now_ch_from_string == '^' || m_now_ch_from_string == ':' ||
       m_now_ch_from_string == '?' || m_now_ch_from_string == ',' )
    return true;
    
  // <=, <, <<
  else if (  m_now_ch_from_string == '<' ) {
    if (  cin.peek() == '=' ) {
      m_now_ch_from_string = cin.get() ;
      m_nowtoken = m_nowtoken + m_now_ch_from_string;
      return true;
    } // if
    
    else if (  cin.peek() == '<' ) {
      m_now_ch_from_string = cin.get() ;
      m_nowtoken = m_nowtoken + m_now_ch_from_string;
      return true;
    } // else if
    
    else
      return true;
  } // else if
  
  // >=, >, >>
  else if (  m_now_ch_from_string == '>' ) {
    if (  cin.peek() == '=' ) {
      m_now_ch_from_string = cin.get() ;
      m_nowtoken = m_nowtoken + m_now_ch_from_string;
      return true;
    } // if

    else if (  cin.peek() == '>' ) {
      m_now_ch_from_string = cin.get() ;
      m_nowtoken = m_nowtoken + m_now_ch_from_string;
      return true;
    } // else if
    
    else
      return true;
    
  } // else if
  
  // ==, =
  else if (  m_now_ch_from_string == '=' ) {
    if (  cin.peek() == '=' ) {
      m_now_ch_from_string = cin.get() ;
      m_nowtoken = m_nowtoken + m_now_ch_from_string;
      return true;
    } // if

    else
      return true;
    
  } // else if
  
  // !=, !
  else if (  m_now_ch_from_string == '!' ) {
    if (  cin.peek() == '=' ) {
      m_now_ch_from_string = cin.get() ;
      m_nowtoken = m_nowtoken + m_now_ch_from_string;
      return true;
    } // if

    else
      return true;
    
  } // else if
  
  // &&, &
  else if (  m_now_ch_from_string == '&' ) {
    if (  cin.peek() == '&' ) {
      m_now_ch_from_string = cin.get() ;
      m_nowtoken = m_nowtoken + m_now_ch_from_string;
      return true;
    } // if

    else
      return true;
    
  } // else if
  
  // ||, |
  else if (  m_now_ch_from_string == '|' ) {
    if (  cin.peek() == '|' ) {
      m_now_ch_from_string = cin.get() ;
      m_nowtoken = m_nowtoken + m_now_ch_from_string;
      return true;
    } // if

    else
      return true;
    
  } // else if
  
  // +=, ++, +
  else if (  m_now_ch_from_string == '+' ) {
    if (  cin.peek() == '=' ) {
      m_now_ch_from_string = cin.get() ;
      m_nowtoken = m_nowtoken + m_now_ch_from_string;
      return true;
    } // if

    else if (  cin.peek() == '+' ) {
      m_now_ch_from_string = cin.get() ;
      m_nowtoken = m_nowtoken + m_now_ch_from_string;
      return true;
    } // if
    
    else
      return true;
    
  } // else if
  
  // -=, --, -
  else if (  m_now_ch_from_string == '-' ) {
    if (  cin.peek() == '=' ) {
      m_now_ch_from_string = cin.get() ;
      m_nowtoken = m_nowtoken + m_now_ch_from_string;
      return true;
    } // if

    else if (  cin.peek() == '-' ) {
      m_now_ch_from_string = cin.get() ;
      m_nowtoken = m_nowtoken + m_now_ch_from_string;
      return true;
    } // if
    
    else
      return true;
    
  } // else if
  
  // *=, *
  else if (  m_now_ch_from_string == '*' ) {
    if (  cin.peek() == '=' ) {
      m_now_ch_from_string = cin.get() ;
      m_nowtoken = m_nowtoken + m_now_ch_from_string;
      return true;
    } // if
    
    else
      return true;
    
  } // else if
  
  // /=, /
  else if (  m_now_ch_from_string == '/' ) {
    if (  cin.peek() == '=' ) {
      m_now_ch_from_string = cin.get() ;
      m_nowtoken = m_nowtoken + m_now_ch_from_string;
      return true;
    } // if
    
    else
      return true;
    
  } // else if
  
  // %=, %
  else if (  m_now_ch_from_string == '%' ) {
    if (  cin.peek() == '=' ) {
      m_now_ch_from_string = cin.get() ;
      m_nowtoken = m_nowtoken + m_now_ch_from_string;
      return true;
    } // if
    
    else
      return true;
    
  } // else if
  else return false;
} // Project::Is_symbol_for_token()

// set Token of Ide to real type
// like: ide "int" -> INT "int"...
void Project::Is_Definition( Token & token ) {
  if ( strcmp( token.token.c_str(), "int" ) == 0 ) {
    token.type = "INT";
    m_now_definition = true;
  } // if
  
  else if ( strcmp( token.token.c_str(), "float" ) == 0 ) {
    token.type = "FLOAT";
    m_now_definition = true;
  } // else if
  
  else if ( strcmp( token.token.c_str(), "char" ) == 0 ) {
    token.type = "CHAR";
    m_now_definition = true;
  } // else if
  
  else if ( strcmp( token.token.c_str(), "bool" ) == 0 ) {
    token.type = "BOOL";
    m_now_definition = true;
  } // else if
  
  else if ( strcmp( token.token.c_str(), "string" ) == 0 ) {
    token.type = "STRING";
    m_now_definition = true;
  } // else if
  
  else if ( strcmp( token.token.c_str(), "void" ) == 0 ) {
    token.type = "VOID";
    m_now_definition = true;
  } // else if
  
  else if ( strcmp( token.token.c_str(), "if" ) == 0 ) {
    token.type = "IF";
  } // else if
  
  else if ( strcmp( token.token.c_str(), "else" ) == 0 ) {
    token.type = "ELSE";
  } // else if
  
  else if ( strcmp( token.token.c_str(), "while" ) == 0 ) {
    token.type = "WHILE";
  } // else if
  
  else if ( strcmp( token.token.c_str(), "do" ) == 0 ) {
    token.type = "DO";
  } // else if
  
  else if ( strcmp( token.token.c_str(), "return" ) == 0 ) {
    token.type = "RETURN";
  } // else if
  
  else if ( strcmp( token.token.c_str(), "true" ) == 0 ||
            strcmp( token.token.c_str(), "false" ) == 0 ) {
    token.type = "CONSTANT";
  } // else if
  
  else {
    token.type = "IDE";
  } // else
  
} // Project::Is_Definition()


// set m_is_peek to false
// take token to get data from m_peek_token
// when m_peek_token is not ";","}" use PeekToken,( avoid skipping "\n")
// do PeekToken() for function_data's space
void Project::GetToken( Token & token ) {
  string type_name = "";
  Token temp_token;
  temp_token.is_million = false;
  string m_nowtoken = "";
  bool num = false;
  bool finish = false;
  bool is_function = false;
  if ( m_while_getExpression == true ) {
  	if ( m_while_condition.size() - 1 > m_expression_loc )
  	  m_expression_loc++;
  } // if
  
  else if ( m_while_getStatement == true ) {
  	if ( m_while_statement.size() - 1 > m_statement_loc )
  	  m_statement_loc++;
  } // else if
  
  
  else if ( m_is_peek == true ) {
  	token = m_peek_token;
  	if ( m_is_while_condition == true )
  	  m_while_condition.push_back( token );
  	if ( m_is_while_statement == true )
  	  m_while_statement.push_back( token ); 
  	m_is_peek = false;
  	if ( m_now_definition == true && m_instruction_str.size() == 0 ) {
      m_instruction_str = m_instruction_str + m_peek_token.token + " ";
    } // if
    
    else if ( m_unrecognized_exist == true || m_unexpected == true || m_undefined_ide == true ) {
      ;
	} // else if
    
    else if ( m_now_definition == true ) {
      temp_token = m_peek_token;
      if ( strcmp( temp_token.token.c_str(), ";" ) != 0 &&
	       strcmp( temp_token.token.c_str(), "}" ) != 0 &&
		   strcmp( temp_token.token.c_str(), "EndInputBufferAppend" ) != 0 ) {
      	PeekToken();
	  } // if
	  
      if ( strcmp( m_peek_token.token.c_str(), "(" ) == 0 ||
	       strcmp( m_peek_token.token.c_str(), "[" ) == 0 ||
		   strcmp( m_peek_token.token.c_str(), "++" ) == 0 ||
		   strcmp( m_peek_token.token.c_str(), "--" ) == 0 ) {
  	    if ( strcmp( m_peek_token.token.c_str(), "[" ) == 0 ) { 
  	  	  m_instruction_str = m_instruction_str + temp_token.token ;
	    } // if
	    
	    else if ( strcmp( m_peek_token.token.c_str(), "++" ) == 0 ||
		          strcmp( m_peek_token.token.c_str(), "--" ) == 0  ) {
	      m_instruction_str = m_instruction_str + temp_token.token ;
		} // else if
	    
	    else if ( strcmp( m_peek_token.token.c_str(), "(" ) == 0 ) {
	      if ( strcmp( temp_token.type.c_str(), "IDE" ) == 0 ) {
	      	m_instruction_str = m_instruction_str + temp_token.token;
		  } // if
		  
		  else {
		  	m_instruction_str = m_instruction_str + temp_token.token + " ";
		  } // else
		  
		} // else if
	  
	  } // if
	  
	  else {
	  	if ( strcmp( temp_token.token.c_str(), "else" ) == 0 ||
	         strcmp( temp_token.token.c_str(), "{" ) == 0 ||
		     strcmp( temp_token.token.c_str(), ";" ) == 0  ) {
	      m_instruction_str = m_instruction_str + temp_token.token + "\n";
	    } // if
	  
	    else if ( strcmp( temp_token.token.c_str(), "}" ) == 0 ) {
	      m_instruction_str = m_instruction_str + temp_token.token + "\n" ;
	    } // else if
	  
        else m_instruction_str = m_instruction_str + temp_token.token + " ";
        
	  } // else
	  
	  

	} // else if
    
    // token = m_peek_token;
    // m_is_peek = false;
    // m_peek_token.token = "";
  } // else if
  
  
  
  
} // Project::GetToken()


// do statemenr or definition or InputBufferAppend
// Complete function, 2ok!
void Project::Is_User_Input( bool & correct ) {
  Token token;
  bool definition_Correct = true, statement_Correct = true;
  bool definition_Is_Get = true, statement_Is_Get = true;
  bool finish = false;
  cout << "> ";
  PeekToken();
  token = m_peek_token;
  if ( strcmp( token.token.c_str(), "InputBufferAppend" ) == 0 ) {
  	GetToken( token );
  	PeekToken();
    token = m_peek_token;
    while ( strcmp( token.token.c_str(), "EndInputBufferAppend" ) != 0 ) {
      GetToken( token );
      m_input_buffer.push_back( token.token );
  	  PeekToken();
      token = m_peek_token;
	} // while
	
	GetToken( token );
	cout << "Input-buffer appended ...\n";
	for ( int i = 0; i < m_input_buffer.size() ; i++ ) {
	  cout << m_input_buffer[i] << "\n";
	} // for
	
  } // if
  
  else {
  	Is_Definition( definition_Correct, definition_Is_Get );
    if ( definition_Correct == true ) {
	  if ( m_undefined_ide == false ) {
	    Skip_final_line();
	    m_now_line = 1;
	  } // if
	
      correct = true;
      while ( finish == false ) {
        cout << "> ";
        if ( m_IsEOF == true ) {
          correct = true;
          finish = true;
        } // if
    
        else {
          PeekToken();
          token = m_peek_token;
          if ( strcmp( token.token.c_str(), "InputBufferAppend" ) == 0 ) {
            GetToken( token );
  	        PeekToken();
            token = m_peek_token;
            while ( strcmp( token.token.c_str(), "EndInputBufferAppend" ) != 0 ) {
              GetToken( token );
              m_input_buffer.push_back( token.token );
  	          PeekToken();
              token = m_peek_token;
	        } // while
	
	        GetToken( token );
	        cout << "Input-buffer appended ...\n";
	        for ( int i = 0; i < m_input_buffer.size() ; i++ ) {
	          cout << m_input_buffer[i] << "\n";
	        } // for
	        
		  } // if
		   
		   
		  else {
		  	Is_Definition( definition_Correct, definition_Is_Get );
		    if ( definition_Correct == true ) {
		      // if ( cin.peek() == '\n' ) {
  	          //  cin.get();	        
	          // } // if
	          if ( m_undefined_ide == false ) {
	      	    Skip_final_line();
	            m_now_line = 1;
	          } // if
	      
		      // Skip_Line();
		    } // if
		
		    else if ( m_unrecognized_exist == true ) {
		      cout << "Line " << m_now_line << " :"  ;
		      cout << " unrecognized token with first char : \'" << m_peek_token.token << "\'\n";
              GetToken( token );
              m_unrecognized_exist = false;
              Skip_Line();
		    } // else if
		
		    else if ( m_undefined_ide == true && definition_Is_Get == true ) {
		      finish = true;
		    } // else if
		
            else if ( definition_Correct == false && definition_Is_Get == true  ) {
              correct = false;
              finish = true;
              PeekToken();
              token = m_peek_token;
              cout << "Line " << m_now_line << " :" << " unexpected token : \'" << token.token << "\'\n";
              // cout << "> unexpected token :\'" << token.token << "\'\n";
              m_unexpected = true;
              GetToken( token ) ;
              m_unexpected = false;
              Skip_Line();
            } // if
        
            else if ( definition_Correct == false ) {
              Is_Statement( statement_Correct, statement_Is_Get ) ;
              if ( statement_Correct == true && m_is_cout == true ) {
                CoutData( m_cout_token );
      	        m_is_cout = false;
	          } // if
	  
	          else if ( statement_Correct == false && m_is_cout == true ) {
	  	        m_is_cout = false;
	          } // else if
              
              if ( statement_Correct == true && m_is_cin == true ) {
      	        CinData( m_cin_token );
      	        m_is_cin = false;
	          } // if
	  
	          else if ( statement_Correct == false && m_is_cin == true ) {
	  	        m_is_cin = false;
	          } // else if
	          
              if ( m_undefined_ide == true ) {
                finish = true;
              } // if
          
              else if ( m_unrecognized_exist == true ) {
          	    cout << "Line " << m_now_line << " :"  ;
			    cout << " unrecognized token with first char : \'" << m_peek_token.token << "\'\n";
          	    GetToken( token );
          	    m_unrecognized_exist = false;
                Skip_Line();
		      } // else if
          
              else if ( statement_Correct == false && statement_Is_Get == true ) {
                PeekToken();
                token = m_peek_token;
                cout << "Line " << m_now_line << " :" << " unexpected token : \'" << token.token << "\'\n";
                // cout << "> unexpected token :\'" << token.token << "\'\n";
                finish = true;
                correct = false;
                m_unexpected = true;
                GetToken( token ) ;
                m_unexpected = false;
                Skip_Line();
              } // else if
          
              else if ( statement_Correct == false ) {
                PeekToken();
                token = m_peek_token;
                cout << "Line " << m_now_line << " :" << " unexpected token : \'" << token.token << "\'\n";
                // cout << "> unexpected token :\'" << token.token << "\'\n";
                finish = true;
                m_unexpected = true;
                GetToken( token ) ;
                m_unexpected = false;
                Skip_Line();
              } // if
          
              else {
          	    if ( statement_Correct == true ) {
	              if ( m_undefined_ide == false ) {
	          	    Skip_final_line();
	                m_now_line = 1;	  
	              } // if
	          
          	      // Skip_Line();
			    } // if
			
                if ( m_is_Done == true ) {
                  finish = true;
                  cout << "Our-C exited ...";
                } // if
            
                else {
                  cout << "Statement executed ...\n";
			    } // else
            
              } // else
          
            } // if
        
            
          } // else
		  	
		  		
		} // else
		  
        if ( m_undefined_ide == false ) m_now_line = 1;
      
      } // while
    
    } // if
    
    else if ( m_unrecognized_exist == true ) {
  	  cout << "Line " << m_now_line << " :"  ;
	  cout << " unrecognized token with first char : \'" << m_peek_token.token << "\'\n";
      GetToken( token );
      m_unrecognized_exist = false;
      Skip_Line();
    } // else if
    
    else if ( m_undefined_ide == true && definition_Is_Get == true ) {
  	  ;
    } // else if
    
    else if ( definition_Correct == false && definition_Is_Get == true  ) {
      correct = false;
      PeekToken();
      token = m_peek_token;
      cout << "Line " << m_now_line << " :" << " unexpected token : \'" << token.token << "\'\n";
      // cout << "> unexpected token :\'" << token.token << "\'\n";
      m_unexpected = true;
      GetToken( token ) ;
      m_unexpected = false;
      Skip_Line();
      if ( m_undefined_ide == false ) m_now_line = 1;
    } // else if
    
    else {
      Is_Statement( statement_Correct, statement_Is_Get ) ;
      if ( statement_Correct == true && m_is_cout == true ) {
      	CoutData( m_cout_token );
      	m_is_cout = false;
	  } // if
	  
	  else if ( statement_Correct == false && m_is_cout == true ) {
	  	m_is_cout = false;
	  } // else if
      
      if ( statement_Correct == true && m_is_cin == true ) {
      	CinData( m_cin_token );
      	m_is_cin = false;
	  } // if
	  
	  else if ( statement_Correct == false && m_is_cin == true ) {
	  	m_is_cin = false;
	  } // else if
	  
      if ( statement_Correct == true ) {
	    if ( m_undefined_ide == false ) {
	  	  Skip_final_line();
	      m_now_line = 1;
	    } // if
	  
        // Skip_Line();
        if ( m_undefined_ide == false ) m_now_line = 1;
        correct = true;
        if ( m_is_Done == true ) {
          finish = true;
          cout << "Our-C exited ...";
        } // if
      
        else if ( m_undefined_ide == true ) {
          finish = true;
        } // else if
      
        else cout << "Statement executed ...\n";
      
        while ( finish == false ) {
      	  cout << "> ";
          if ( m_IsEOF == true ) {
            correct = true;
            finish = true;
          } // if
    
          else {
          	if ( strcmp( token.token.c_str(), "InputBufferAppend" ) == 0 ) {
          	  GetToken( token );
  	          PeekToken();
              token = m_peek_token;
              while ( strcmp( token.token.c_str(), "EndInputBufferAppend" ) != 0 ) {
                GetToken( token );
                m_input_buffer.push_back( token.token );
  	            PeekToken();
                token = m_peek_token;
	          } // while
	
	          GetToken( token );
	          cout << "Input-buffer appended ...\n";
	          for ( int i = 0; i < m_input_buffer.size() ; i++ ) {
	            cout << m_input_buffer[i] << "\n";
	          } // for
	          
			} // if
          	
          	else {
          	  Is_Definition( definition_Correct, definition_Is_Get );
              if ( definition_Correct == true ) {
                // if ( cin.peek() == '\n' ) {
  	            //  cin.get();	            
	            // } // if
	            if ( m_undefined_ide == false ) {
	              Skip_final_line();
	              m_now_line = 1;
	            } // if
	        
                // Skip_Line();
		      } // if
		  
		      else if ( m_unrecognized_exist == true ) {
		  	    cout << "Line " << m_now_line << " :"  ;
			    cout << " unrecognized token with first char : \'" << m_peek_token.token << "\'\n";
                GetToken( token );
                m_unrecognized_exist = false;
                Skip_Line();
		      } // else if
		  
		      else if ( m_undefined_ide == true && definition_Is_Get == true ) {
		        finish = true;
		      } // else if
		  
              else if ( definition_Correct == false && definition_Is_Get == true ) {
                correct = false;
                finish = true;
                PeekToken();
                token = m_peek_token;
                cout << "Line " << m_now_line << " :" << " unexpected token : \'" << token.token << "\'\n";
                // cout << "> unexpected token :\'" << token.token << "\'\n";
                m_unexpected = true;
                GetToken( token ) ;
                m_unexpected = false;
                Skip_Line();
              } // else if
          
              else if ( definition_Correct == false ) {
                Is_Statement( statement_Correct, statement_Is_Get ) ;
                if ( statement_Correct == true && m_is_cout == true ) {
      	          CoutData( m_cout_token );
      	          m_is_cout = false;
	            } // if
	  
	            else if ( statement_Correct == false && m_is_cout == true ) {
	  	          m_is_cout = false;
	            } // else if
                
                if ( statement_Correct == true && m_is_cin == true ) {
      	          CinData( m_cin_token );
      	          m_is_cin = false;
	            } // if
	  
	            else if ( statement_Correct == false && m_is_cin == true ) {
	  	          m_is_cin = false;
	            } // else if
                
                if ( statement_Correct == true ) {
                  // if ( cin.peek() == '\n' ) {
  	              //  cin.get();	            
	              // } // if
	              if ( m_undefined_ide == false ) {
	          	    Skip_final_line();
	                m_now_line = 1;
	              } // if
	          
                  // Skip_Line();
			    } // if
			
                if ( m_undefined_ide == true ) {
                  finish = true;
                } // if
            
                else if ( m_unrecognized_exist == true ) {
                  cout << "Line " << m_now_line << " :"  ;
			      cout << " unrecognized token with first char : \'" << m_peek_token.token << "\'\n";
                  GetToken( token );
                  m_unrecognized_exist = false;
                  Skip_Line();
			    } // else if
            
                else if ( statement_Correct == false && statement_Is_Get == true ) {
                  PeekToken();
                  token = m_peek_token;
                  cout << "Line " << m_now_line << " :" << " unexpected token : \'" << token.token << "\'\n";
                  // cout << "> unexpected token :\'" << token.token << "\'\n";
                  finish = true;
                  correct = false;
                  m_unexpected = true;
                  GetToken( token ) ;
                  m_unexpected = false;
                  Skip_Line();
                } // else if
            
                else if ( statement_Correct == false ) {
                  PeekToken();
                  token = m_peek_token;
                  cout << "Line " << m_now_line << " :" << " unexpected token : \'" << token.token << "\'\n";
                  // cout << "> unexpected token :\'" << token.token << "\'\n";
                  finish = true;
                  m_unexpected = true;
                  GetToken( token ) ;
                  m_unexpected = false;
                  Skip_Line();
                } // if
            
                else {
                  if ( m_is_Done == true ) {
                    finish = true;
                    cout << "Our-C exited ...";
                  } // if
              
                  else {
              	    cout << "Statement executed ...\n";
			      } // else 
              
                } // else
          
              } // if
              
			} // else
            
          } // else
        
          if ( m_undefined_ide == false ) m_now_line = 1;
        
        } // while
        
      } // if
    
      else {
        if ( m_undefined_ide == true ) {
          finish = true;
        } // if
      
        else if ( m_unrecognized_exist == true ) {
          cout << "Line " << m_now_line << " :"  ;
		  cout << " unrecognized token with first char : \'" << m_peek_token.token << "\'\n";
          GetToken( token );
          m_unrecognized_exist = false;
          Skip_Line();
	    } // else if
      
        else {
          PeekToken();
          token = m_peek_token;
          cout << "Line " << m_now_line << " :" << " unexpected token : \'" << token.token << "\'\n";
          // cout << "> unexpected token :\'" << token.token << "\'\n";
          correct = false;
          m_unexpected = true;
          GetToken( token ) ;
          m_unexpected = false;
          Skip_Line();    
          if ( m_undefined_ide == false ) m_now_line = 1;
        } // else

      } // else
    
    } // else
    
    if ( m_undefined_ide == false ) m_now_line = 1;
  } // else
   
  
} // Project::Is_User_Input()


// 2 possibilities, void or (int/bool/string.....)
// Complete function, 2ok!
void Project::Is_Definition( bool & correct, bool & Is_Get ) {
  Token token;
  Value value;
  Data tmp_data;
  Token tmp_token;
  Value tmp_value;
  int loc = 0;
  int define_size = m_define_table.size() - 1;
  bool is_fun = false;
  bool is_in_definedTable = false;
  bool is_in_functTable = false;
  string id_name = "";
  m_instruction_str = "";
  PeekToken();
  token = m_peek_token;
  m_function = false;
  bool fun_Def_WithoutID_Correct = false;
  bool fun_Def_WithoutID_Is_Get = true;
  bool type_specifier_Correct = false;
  bool type_specifier_Is_Get = true;
  bool fun_def_or_declarators_Correct = false;
  bool fun_def_or_declarators_Is_Get = true;
  if ( strcmp( token.type.c_str(), "VOID" ) == 0 ) {
    GetToken( token );
    PeekToken();
    token = m_peek_token;
    if ( strcmp( token.type.c_str(), "IDE" ) == 0 ) {
      GetToken( token );    
      value.token_name = token;
      tmp_data.str = token.token;
      m_definition_list.push_back( tmp_data ) ;
      id_name = token.token + "()";
      // function
      if ( 65 <= token.token.at( 0 ) && token.token.at( 0 ) <= 90 ) {
      	m_function = true;
      	// check is it exist
      	for ( int i = 0; i < m_fuction_table.size() ; i++ ) {
      	  if ( strcmp( token.token.c_str(), m_fuction_table[i].token.c_str() ) == 0 ) {
      	    is_in_functTable = true;
      	    loc = i;
		  } // if
		  
		} // for
		
		if ( is_in_functTable == false ) m_fuction_table.push_back( token );
		// when exist, move loc to last
		else {
		  tmp_token = m_fuction_table[loc];
		  m_fuction_table.erase( m_fuction_table.begin() + loc );
		  m_fuction_table.push_back( tmp_token );
		} // else
		
        is_fun = true;
      } // if
        
      // not function,variable
      else {
      	// check is it exist
      	for ( int i = 0; i < m_define_table.size() ; i++ ) {
      	  if ( strcmp( token.token.c_str(), m_define_table[i].token_name.token.c_str() ) == 0 ) {
      	    is_in_definedTable = true;
      	    loc = i;
		  } // if
		  
		} // for
		
		if ( is_in_definedTable == false ) m_define_table.push_back( value );
		// when exist, move loc to last
		else {
		  tmp_value = m_define_table[loc];
		  m_define_table.erase( m_define_table.begin() + loc );
		  m_define_table.push_back( tmp_value );
		} // else
		
	  } // else
	  
      Is_Function_definition_without_ID( fun_Def_WithoutID_Correct, fun_Def_WithoutID_Is_Get );
      if ( fun_Def_WithoutID_Correct == true ) {
        correct = true; 
        if ( is_in_definedTable == true ) {
          cout << "New definition of " << id_name << " entered ...\n";
		} // if
		
		else if ( is_in_functTable == true ) {
		  cout << "New definition of " << id_name << " entered ...\n";
		} // else if
		
        else cout << "Definition of " << id_name << " entered ...\n";
      } // if
      
      else correct = false;
    } // if
    
    else correct = false;
  } // if
  
  else {
  	m_type = token.token;
    Is_Type_specifier( type_specifier_Correct, type_specifier_Is_Get );
    if ( type_specifier_Correct == true ) {
      PeekToken();
      token = m_peek_token;
      if ( strcmp( token.type.c_str(), "IDE" ) == 0 ) {
        GetToken( token );
        value.token_name = token;
        tmp_data.str = token.token;
        m_definition_list.push_back( tmp_data ) ;
        // function
        id_name = token.token;
        if ( 65 <= token.token.at( 0 ) && token.token.at( 0 ) <= 90 ) {
          m_function = true;
      	  for ( int i = 0; i < m_fuction_table.size() ; i++ ) {
      	    if ( strcmp( token.token.c_str(), m_fuction_table[i].token.c_str() ) == 0 ) {
      	      is_in_functTable = true;
      	      loc = i;
		    } // if
		  
		  } // for
		
		  if ( is_in_functTable == false ) m_fuction_table.push_back( token );
		  else {
		    tmp_token = m_fuction_table[loc];
		    m_fuction_table.erase( m_fuction_table.begin() + loc );
		    m_fuction_table.push_back( tmp_token );
		  } // else
		
          is_fun = true;
          m_definition_list[ m_definition_list.size() - 1 ].is_function = true;
        } // if
        
        else {
      	  for ( int i = 0; i < m_define_table.size() ; i++ ) {
      	    if ( strcmp( token.token.c_str(), m_define_table[i].token_name.token.c_str() ) == 0 ) {
      	      is_in_definedTable = true;
      	      loc = i;
		    } // if
		  
		  } // for
		
		  if ( is_in_definedTable == false ) {
		  	m_define_table.push_back( value );
		  	m_definition_list[ m_definition_list.size() - 1 ].is_rebuild = false;
		  } // if
		  
		  else {
		    tmp_value = m_define_table[loc];
		    m_define_table.erase( m_define_table.begin() + loc );
		    m_define_table.push_back( tmp_value );
		    m_definition_list[ m_definition_list.size() - 1 ].is_rebuild = true;
		  } // else
		  
		  m_define_table[ m_define_table.size() - 1 ].token_name.function_data = token.token;
		  m_definition_list[ m_definition_list.size() - 1 ].is_function = false; 
	    } // else
		
        Is_Function_definition_or_declarators( fun_def_or_declarators_Correct, 
                                               fun_def_or_declarators_Is_Get );
        if ( fun_def_or_declarators_Correct == true ) {
          correct = true;
          for ( int i = 0; i < m_definition_list.size() ; i++ ) {
            if ( m_definition_list[i].is_rebuild == false && 
			     m_definition_list[i].is_function == false ) {
              cout << "Definition of " << m_definition_list[i].str ;
			  cout << " entered ...\n";
			} // if
			
			else if ( m_definition_list[i].is_rebuild == true && 
			          m_definition_list[i].is_function == false ) {
			  cout << "New definition of " << m_definition_list[i].str ;
			  cout << " entered ...\n";
			} // else if
			
			else if ( m_definition_list[i].is_function == true ) {
			  if ( is_in_functTable == true ) {
			  	cout << "New definition of " << m_definition_list[i].str ;
			    if ( m_definition_list[i].is_function == true ) cout << "()";
			    cout << " entered ...\n";
			  } // if
			  
			  else {
			  	cout << "Definition of " << m_definition_list[i].str ;
                if ( m_definition_list[i].is_function == true ) cout << "()";
			    cout << " entered ...\n";
			  } // else
			  
			} // else if
			
			

			
		  } // for
          
          
          // if ( is_in_definedTable == true ) {
          //  cout << "New definition of " << id_name << " entered ...\n";
		  // } // if
		
          // else {
          //	for ( int i = 0; i < m_definition_list.size() ; i++ ) {
          //	  cout << "Definition of " << m_definition_list[i].str << " entered ...\n";
		  // } // for
			
		  // } // else
		  
		  m_definition_list.clear();
		  
        } // if
        
        else correct = false;
        
      } // if
      
      else correct = false;
        
    } // if
    
    else if ( type_specifier_Correct == false && type_specifier_Is_Get == true ) {
      correct = false;
    } // else if
    
    else {
      correct = false;
      Is_Get = false;
    } // else
    
  } // else
  
  if ( m_now_definition == true && is_fun == true && correct == true ) {
  	m_fuction_table[ m_fuction_table.size() - 1 ].function_data = "";
  	// set token's function_data
  	for ( int i = 0; i < m_instruction_str.size() - 1 ; i++ ) {
  	  m_fuction_table[ m_fuction_table.size() - 1 ].function_data = 
  	  m_fuction_table[ m_fuction_table.size() - 1 ].function_data + m_instruction_str[i];
	} // for
	
    // m_fuction_table[ m_fuction_table.size() - 1 ].function_data = m_instruction_str;
  } // if
  
  else if ( m_now_definition == true && is_fun == false && correct == true ) {
  	for ( int i = m_define_table.size() - 1; i > define_size ; i-- ) {
      m_define_table[i].token_name.function_data = m_type + 
	  " " + m_define_table[i].token_name.function_data + " ;";
	} // for
	
  } // else if
  
  if ( correct == false && m_now_definition == true ) {
    if ( is_fun == false ) {
      for ( int i = m_define_table.size() - 1; i > define_size ; i-- ) {
      	m_define_table.erase( m_define_table.end() );
	  } // for
	  
	} // if
	
	else m_fuction_table.erase( m_fuction_table.end() ) ;
	
  } // if
  
  /*
  PeekToken();
  token = m_peek_token;
  if ( m_now_definition == true && strcmp( token.token.c_str(), "int" ) != 0
       && strcmp( token.token.c_str(), "float" ) != 0
       && strcmp( token.token.c_str(), "char" ) != 0
       && strcmp( token.token.c_str(), "bool" ) != 0
	   && strcmp( token.token.c_str(), "string" ) != 0
	   && strcmp( token.token.c_str(), "void" ) != 0
     ) {
    m_now_definition = false;	
  } // if
  */
  
  if ( correct == true ) {
  	SetArraryData();
  } // if
  
  /*
  if ( correct == true && m_tmp_arrary_table.size() != 0 ) {
    for ( int i = 0; i < m_tmp_arrary_table.size() ; i++ ) {
      m_tmp_arrary_table.push_back( m_tmp_arrary_table[i] );
	} // for
	
	SetArrary();
	m_tmp_arrary_table.clear();
	
  } // if
  */
  
  // if ( correct == false ) {
  //	m_tmp_arrary_table.clear();
  // } // if
  
  // set m_now_definition to false, except next token is definition(int,bool,..)
  if ( Is_Get == true && m_is_peek == false ) m_now_definition = false;	
  m_space_num = 0;
  m_function = false;
  m_definition_list.clear();
  // cout << "==" << m_instruction_str << "\n";
  // cout << "!!" << m_define_table[ m_define_table.size() - 1 ].token << "\n";
  
} // Project::Is_Definition()

// Complete function, 2ok!
void Project::Is_Sign( bool & correct, bool & Is_Get, Token & value ) {
  Token token;
  PeekToken();
  token = m_peek_token;
  if ( strcmp( token.token.c_str(), "+" ) == 0 ||
       strcmp( token.token.c_str(), "-" ) == 0 ||
       strcmp( token.token.c_str(), "!" ) == 0 ) 
  {
    GetToken( token );
    if ( strcmp( value.token.c_str(), "+" ) == 0 ||
         strcmp( value.token.c_str(), "-" ) == 0 ||
         strcmp( value.token.c_str(), "!" ) == 0 ) {
      if ( strcmp( token.token.c_str(), "+" ) == 0 ) {
      	;
	  } // if
	  
	  else if ( strcmp( token.token.c_str(), "-" ) == 0 ) {
	    if ( strcmp( value.token.c_str(), "+" ) == 0 ) {
	      value.token = "-";
		} // if
		
		else if ( strcmp( value.token.c_str(), "-" ) == 0 ) {
		  value.token = "+";
		} // else if
		
	  } // else if
	  
	  // only two properties
	  // !, !!
	  else if ( strcmp( token.token.c_str(), "!" ) == 0 ) {
	  	value.token = value.token + "!";
	  } // else if
	  
	} // if
	
    else value.token = token.token;
    correct = true;
  } // if
  
  else {
    correct = false;
    Is_Get = false;
  } // else

} // Project::Is_Sign()


// Complete function, 2ok!
void Project::Is_Statement( bool & correct, bool & Is_Get ) {
  Token token;
  Token expression_value1;
  bool expression_Correct = false;
  bool expression_Is_Get = true;
  bool statement_Correct = false;
  bool statement_Is_Get = true;
  bool compound_statement_Correct = false;
  bool compound_statement_Is_Get = true;
  PeekToken();
  token = m_peek_token;
  if (  strcmp( token.token.c_str(), ";" ) != 0 ) {
    m_is_Done = false;
  } // if
  
  if (  strcmp( token.token.c_str(), ";" ) == 0 ) {
    GetToken( token );
    correct = true;
  } // if

  else if ( strcmp( token.type.c_str(), "RETURN" ) == 0 ) {
    GetToken( token );
    Is_Expression( expression_Correct, expression_Is_Get, expression_value1 );
    if ( expression_Correct == false && expression_Is_Get == true ) {
      correct = false;  
    } // if
    
    else {
      PeekToken();
      token = m_peek_token;
      if ( strcmp( token.token.c_str(), ";" ) == 0 ) {
        GetToken( token );
        correct = true;
      } // if
    
      else correct = false;
      
    } // else
    
  } // else if
  
  else if ( strcmp( token.type.c_str(), "IF" ) == 0 ) {
    GetToken( token );
    // m_space_num = m_space_num + 2;
    PeekToken();
    token = m_peek_token;
    if ( strcmp( token.token.c_str(), "(" ) == 0 ) {
      GetToken( token );
      Is_Expression( expression_Correct, expression_Is_Get, expression_value1 );
      if ( expression_Correct == false ) {
        correct = false;    
      } // if
      
      else {
      	if ( strcmp( expression_value1.token.c_str(), "false" ) == 0 ) {
      	  m_shouldnot_operator_list2.push_back( true ) ;
		} // if
		
		else m_shouldnot_operator_list2.push_back( false ) ;
		
		// m_shouldnot_operator = true;
        PeekToken();
        token = m_peek_token;
        if ( strcmp( token.token.c_str(), ")" ) == 0 ) {
          GetToken( token );
          Is_Statement( statement_Correct, statement_Is_Get );
          m_shouldnot_operator_list2.erase( m_shouldnot_operator_list2.end() );
          // m_shouldnot_operator = false;
          if ( statement_Correct == false ) {
            correct = false;
          } // if
          
          else {
            PeekToken();
            token = m_peek_token;
            if ( strcmp( expression_value1.token.c_str(), "true" ) == 0 ) {
              m_shouldnot_operator_list2.push_back( true ) ;
			} // if
			
			else m_shouldnot_operator_list2.push_back( false ) ;
			// m_shouldnot_operator = true;
            if ( strcmp( token.type.c_str(), "ELSE" ) == 0 ) {
              GetToken( token );
              // for function_data's space
              m_space_num = m_space_num + 2;
              Is_Statement( statement_Correct, statement_Is_Get );
              m_shouldnot_operator_list2.erase( m_shouldnot_operator_list2.end() );
              // m_shouldnot_operator = false;
              if ( statement_Correct == true ) {
                correct = true;
			    
              } // if
              
              else correct = false;
              
            } // if
            
            else {     
              correct = true;
            } // else
            
          } // else
          
        } // if
        
        else correct = false;
        
      } // else
      
    } // if
    
    else correct = false;
    
  } // else if
  
  else if ( strcmp( token.type.c_str(), "WHILE" ) == 0 ) {
    GetToken( token );
    PeekToken();
    token = m_peek_token;
    if ( strcmp( token.token.c_str(), "(" ) == 0 ) {
      GetToken( token );
      m_is_while_condition = true;
      Is_Expression( expression_Correct, expression_Is_Get, expression_value1 );
      m_is_while_condition = false;
      if ( expression_Correct == false ) {
        correct = false;    
      } // if
      
      else {
        PeekToken();
        token = m_peek_token;
        if ( strcmp( token.token.c_str(), ")" ) == 0 ) {
          GetToken( token );
          m_is_while_statement = true;
          Is_Statement( statement_Correct, statement_Is_Get );
          m_is_while_statement = false;
          if ( statement_Correct == true ) {
          	m_is_while = true;
          	// set lock, m_while_getExpression == true,
          	// GetToken only can use while_condition
          	m_while_getExpression = true;
          	Is_Expression( expression_Correct, expression_Is_Get, expression_value1 );
          	// cancel loc
			m_while_getExpression = false;
			
			
			
            // m_while_getStatement = true;
          	while ( strcmp( expression_value1.token.c_str(), "true" ) == 0 ) {
          	  m_expression_loc = 0;
          	  // set lock, m_while_getStatement == true,
          	  // GetToken only can use while_statement
          	  m_while_getStatement = true;
          	  Is_Statement( statement_Correct, statement_Is_Get );
          	  // cancel loc
          	  m_while_getStatement = false;
              m_statement_loc = 0;
          	  m_while_getExpression = true;
          	  Is_Expression( expression_Correct, expression_Is_Get, expression_value1 );
          	  m_while_getExpression = false;

			} // while
          	
          	m_statement_loc = 0;
          	m_expression_loc = 0;
            correct = true;
          } // if
          
          else {
            correct = false;
          } // else
          
        } // if
        
        else correct = false;
        
      } // else
      
    } // if
    
    else correct = false;
    
    m_is_while = false;
    // for ( int i = 0 ; i < m_while_condition.size() ; i++ ) {
    //  cout << m_while_condition[i].token << "\n";
	// } // for
	
	// cout << "\n\n\n";
	// for ( int i = 0 ; i < m_while_statement.size() ; i++ ) {
    //  cout << m_while_statement[i].token << "\n";
	// } // for
    
	// cout << "\n\n\n";
	m_while_condition.clear();
	m_while_statement.clear();
  } // else if
  
  
  else if ( strcmp( token.type.c_str(), "DO" ) == 0 ) {
    GetToken( token );
    Is_Statement( statement_Correct, statement_Is_Get );
    if ( statement_Correct == false ) {
      correct = false;
    } // if
    
    else {
      PeekToken();
      token = m_peek_token;
      if ( strcmp( token.type.c_str(), "WHILE" ) == 0 ) {
        GetToken( token );
        PeekToken();
        token = m_peek_token;
        if ( strcmp( token.token.c_str(), "(" ) == 0 ) {
          GetToken( token );
          Is_Expression( expression_Correct, expression_Is_Get, expression_value1 );
          if ( expression_Correct == false ) {
            correct = false;    
          } // if
      
          else {
            PeekToken();
            token = m_peek_token;
            if ( strcmp( token.token.c_str(), ")" ) == 0 ) {
              GetToken( token );
              PeekToken();
              token = m_peek_token;
              if ( strcmp( token.token.c_str(), ";" ) == 0 ) {
                GetToken( token );
                correct = true;
              } // if
              
              else correct = false;
          
            } // if
        
            else correct = false;
        
          } // else
      
        } // if
        
        else correct = false;
        
      } // if
      
      else correct = false;
      
    } // else
    
  } // else if
  
  else {
    Is_Compound_statement( compound_statement_Correct, compound_statement_Is_Get ) ;
    if ( compound_statement_Correct == true ) {
      correct = true;
    } // if
    
    else if ( compound_statement_Correct == false && compound_statement_Is_Get == true ) {
      correct = false;
    } // else if
    
    else {
      Is_Expression( expression_Correct, expression_Is_Get, expression_value1 );
      if ( expression_Correct == true ) {
        PeekToken();
        token = m_peek_token;
        if ( m_undefined_ide == true ) {
          correct = false ;
        } // if
        
        else if ( strcmp( token.token.c_str(), ";" ) == 0 ) {
          GetToken( token );
          correct = true ;
        } // if
        
        else {
          correct = false;
        } // else 
        
      } // if
      
      else if ( expression_Correct == false && expression_Is_Get == true ) {
        correct = false;
      } // else if
      
      else {
        Is_Get = false;
        correct = false;
      } // else
      
    } // else
    
  } // else
  
  if ( correct == true && m_PP_table.size() != 0 ) {
  	// Do_Last_PP();
  	// m_PP_table.clear();
  } // if
  
  if ( correct == true && m_MM_table.size() != 0 ) {
  	// Do_Last_MM();
  	// m_MM_table.clear();
  } // if
  
  if ( correct == false ) {
  	m_MM_table.clear();
  	m_PP_table.clear();
    m_ListAllFunctions = false;
    m_ListFunction = false;
    m_ListVariable = false;
    m_ListAllVariables = false;
  } // if
  
  if ( m_ListAllFunctions == true ) {
    ListAllFunctions();
    m_ListAllFunctions = false;
  } // if
  
  if ( m_ListFunction == true ) {
    ListFunction();
    m_ListFunction = false;
  } // if
  
  if ( m_ListAllVariables == true ) {
  	ListAllVariables();
  	m_ListAllVariables = false;
  } // if
  
  if ( m_ListVariable == true ) {
  	ListVariable();
  	m_ListVariable = false;
  } // if

} // Project::Is_Statement()

// Define
// Complete function, 2ok!
void Project::Is_Function_definition_without_ID( bool & correct, bool & Is_Get ) {
  Token token;
  bool formal_parameter_list_Correct = false;
  bool formal_parameter_list_Is_Get = true;
  bool compound_statement_Correct = false;
  bool compound_statement_Is_Get = true;
  PeekToken();
  token = m_peek_token;
  if ( strcmp( token.token.c_str(), "(" ) == 0 ) {
    GetToken( token );
    PeekToken();
    token = m_peek_token;
    if ( strcmp( token.type.c_str(), "VOID" ) == 0 ) {
      GetToken( token );
    } // if
    
    else {
      Is_Formal_parameter_list( formal_parameter_list_Correct, formal_parameter_list_Is_Get ) ;
    } // else
    
    if ( formal_parameter_list_Correct == false && formal_parameter_list_Is_Get == true ) {
      correct = false;
    } // if
    
    else {
      PeekToken();
      token = m_peek_token;
      if ( strcmp( token.token.c_str(), ")" ) == 0 ) {
        GetToken( token );
        Is_Compound_statement( compound_statement_Correct, compound_statement_Is_Get );
        // PeekToken();
        // token = m_peek_token;
        if ( compound_statement_Correct == true ) {
          correct = true;
          // PeekToken();
          // token = m_peek_token;
        } // if
        
        else {
          correct = false;
        } // else
      
      } // if
      
      else correct = false;
      
    } // else
    
    
  } // if
  
  else {
    correct = false;
    Is_Get = false;
  } // else
  

} // Project::Is_Function_definition_without_ID()

// Complete function, 2ok!
void Project::Is_Type_specifier( bool & correct, bool & Is_Get ) {
  Token token;
  PeekToken();
  token = m_peek_token;
  if ( strcmp( token.type.c_str(), "INT" ) == 0 || 
       strcmp( token.type.c_str(), "CHAR" ) == 0  || 
       strcmp( token.type.c_str(), "FLOAT" ) == 0 || 
       strcmp( token.type.c_str(), "STRING" ) == 0 || 
       strcmp( token.type.c_str(), "BOOL" ) == 0 ) {
    GetToken( token );
    m_now_definition = true;
    correct = true;     
  } // if
  
  else {
    correct = false;
    Is_Get = false;
  } // else
  
} // Project::Is_Type_specifier()

// Define
// Complete function, 2ok!
void Project::Is_Function_definition_or_declarators( bool & correct, bool & Is_Get ) {
  bool fun_def_without_ID_Correct = false;
  bool fun_def_without_ID_Is_Get = true;
  bool rest_of_declarators_Correct = false;
  bool rest_of_declarators_Is_Get = true;
  Is_Function_definition_without_ID( fun_def_without_ID_Correct, fun_def_without_ID_Is_Get );
  if ( fun_def_without_ID_Correct == true ) {
    correct = true;
  } // if
  
  else if ( fun_def_without_ID_Correct == false && fun_def_without_ID_Is_Get == true ) {
    correct = false;
  } // else if
  
  else {
    Is_Rest_of_declarators( rest_of_declarators_Correct, rest_of_declarators_Is_Get );
    if ( rest_of_declarators_Correct == true ) {
      correct = true;
    } // if
    
    else if ( rest_of_declarators_Correct == false && rest_of_declarators_Is_Get == true ) {
      correct = false;
    } // else if
    
    else {
      correct = false;
      Is_Get = false;
    } // else
    
  } // else

} // Project::Is_Function_definition_or_declarators()

// Define
// Complete function, 2ok!
void Project::Is_Rest_of_declarators( bool & correct, bool & Is_Get ) {
  bool ide_exist = false;
  bool getToken_in_squareBrackets = false;
  bool is_in_Definetable = false;
  bool is_in_Localtable = false;
  Data tmp_data; 
  Arrary_num tmp_arrary_num ;
  vector<string> arrary_size_list ;
  Token token;
  Value value;
  PeekToken();
  token = m_peek_token;
  if ( strcmp( token.token.c_str(), "[" ) == 0 ) {
    GetToken( token );
    m_define_table[ m_define_table.size() - 1 ].token_name.
	function_data = m_define_table[ m_define_table.size() - 1 ].
	token_name.function_data + token.token + " ";
	
    getToken_in_squareBrackets = true;
    PeekToken();
    token = m_peek_token;
    if ( strcmp( token.type.c_str(), "CONSTANT" ) == 0 ) {
      GetToken( token );
      m_define_table[ m_define_table.size() - 1 ].value.is_arrary = true;
      m_define_table[ m_define_table.size() - 1 ].value.size_str = token.token;
      if ( m_define_table.size() != 0 ) {
      	tmp_arrary_num.token_name = m_define_table[ m_define_table.size() - 1 ].token_name;
      	tmp_arrary_num.size_str = token.token;
      	// m_tmp_arrary_table.push_back( tmp_arrary_num );
	  } // if
	  
      // tmp_arrary_num.token_name = m_define_table[ m_define_table.size() - 1 ].token_name;
      // m_define_table.erase( m_define_table.begin() + m_define_table.size() - 1 ) ;
      
      // arrary_size_list.push_back( token.token );
      
      m_define_table[ m_define_table.size() - 1 ].
	  token_name.function_data = m_define_table[ m_define_table.size() - 1 ].
	  token_name.function_data + token.token + " ";
	  
	  
      PeekToken();
      token = m_peek_token;
      if ( strcmp( token.token.c_str(), "]" ) == 0 ) {
        GetToken( token );
        
        m_define_table[ m_define_table.size() - 1 ].
		token_name.function_data = m_define_table[ m_define_table.size() - 1 ].token_name.
		function_data + token.token;	
		
		
      } // if
      
      else correct = false;
      
    } // if
    
    else correct = false;
    
  } // if
  
  PeekToken();
  token = m_peek_token;
  while ( strcmp( token.token.c_str(), "," ) == 0 ) {
    GetToken( token );
    getToken_in_squareBrackets = true;
    PeekToken();
    token = m_peek_token;
    if ( strcmp( token.type.c_str(), "IDE" ) == 0 ) {
      //
      GetToken( token );
      tmp_arrary_num.token_name = token;
      // arrary_size_list.push_back( token.token );
      value.token_name = token;
      tmp_data.str = token.token;
      if ( m_declaration == true ) {
      	m_localData_table.push_back( value );
        m_localData_table[ m_localData_table.size() - 1 ].token_name.function_data = token.token ;
	    
	  } // if
      
      else {
      	m_definition_list.push_back( tmp_data ) ;
        for ( int i = 0; i < m_define_table.size() ; i++ ) {
          if ( strcmp( token.token.c_str(), m_define_table[i].token_name.token.c_str() ) == 0 ) {
            is_in_Definetable = true;
		  } // if
        
	    } // for
	  
        if ( is_in_Definetable == false ) {
      	  m_define_table.push_back( value );
      	  m_definition_list[ m_definition_list.size() - 1 ].is_rebuild = false;
	    } // if
	  
	    else {
	  	  m_definition_list[ m_definition_list.size() - 1 ].is_rebuild = true;
	    } // else
	  
	    is_in_Definetable = false;
        m_define_table[ m_define_table.size() - 1 ].token_name.function_data = token.token ;
        
	  } // else
	  
      
      
      PeekToken();
      token = m_peek_token;
      if ( strcmp( token.token.c_str(), "[" ) == 0 ) {
        GetToken( token );
        if (  m_declaration == true ) {
          m_localData_table[ m_localData_table.size() - 1 ].
		  token_name.function_data = m_localData_table[ m_localData_table.size() - 1 ].
		  token_name.function_data + token.token + " ";	
		} // if
		
		else {
		  m_define_table[ m_define_table.size() - 1 ].
		  token_name.function_data = m_define_table[ m_define_table.size() - 1 ].
		  token_name.function_data + token.token + " ";	
		} // else
		
        
        PeekToken();
        token = m_peek_token;
        if ( strcmp( token.type.c_str(), "CONSTANT" ) == 0 ) {
          GetToken( token );
          if (  m_declaration == true ) {
          	m_localData_table[ m_localData_table.size() - 1 ].value.is_arrary = true;
            m_localData_table[ m_localData_table.size() - 1 ].value.size_str = token.token;
		  } // if
		  
		  else {
		    m_define_table[ m_define_table.size() - 1 ].value.is_arrary = true;
            m_define_table[ m_define_table.size() - 1 ].value.size_str = token.token;	
		  } // else
          
          tmp_arrary_num.size_str = token.token;
          // m_tmp_arrary_table.push_back( tmp_arrary_num );

          if (  m_declaration == true ) {
          	m_localData_table[ m_localData_table.size() - 1 ].
		    token_name.function_data = m_localData_table[ m_localData_table.size() - 1 ].
		    token_name.function_data + token.token + " ";
		  } // if
		  
		  else {
		  	m_define_table[ m_define_table.size() - 1 ].
		    token_name.function_data = m_define_table[ m_define_table.size() - 1 ].
		    token_name.function_data + token.token + " ";
		  } // else
          
          PeekToken();
          token = m_peek_token;
          if ( strcmp( token.token.c_str(), "]" ) == 0 ) {
            GetToken( token );
            if (  m_declaration == true ) {
              m_localData_table[ m_localData_table.size() - 1 ].token_name.
		      function_data = m_localData_table[ m_localData_table.size() - 1 ].
			  token_name.function_data + token.token ;
			} // if
            
            else {
              m_define_table[ m_define_table.size() - 1 ].token_name.
		      function_data = m_define_table[ m_define_table.size() - 1 ].
			  token_name.function_data + token.token ;	
			} // else
			
            
            PeekToken();
            token = m_peek_token;
          } // if
            
          else correct = false;
             
        } // if
          
        else correct = false;
          
      } // if
        
      
        
    } // if
    
    else correct = false;
      
  } // while
    
  PeekToken();
  token = m_peek_token;
  if ( strcmp( token.token.c_str(), ";" ) == 0 ) {
    GetToken( token );
    correct = true; 
  } // if
    
  else {
    correct = false;
    if ( getToken_in_squareBrackets == false ) {
      Is_Get = false;
    } // if
    
  } // else
  
} // Project::Is_Rest_of_declarators()

// Complete function, 2ok!
void Project::Is_Formal_parameter_list( bool & correct, bool & Is_Get ) {
  Token token;
  bool getToken_in_squareBrackets = false;
  bool type_specifier_Correct = false;
  bool type_specifier_Is_Get = true;
  Is_Type_specifier( type_specifier_Correct, type_specifier_Is_Get );
  if ( type_specifier_Correct == true ) {
    PeekToken();
    token = m_peek_token;
    if ( strcmp( token.token.c_str(), "&" ) == 0 ) {
      GetToken( token );
      
    } // if
    
    PeekToken();
    token = m_peek_token;
    if ( strcmp( token.type.c_str(), "IDE" ) == 0 ) {
      correct = true;
      GetToken( token );
      m_fuction_table[m_fuction_table.size()-1].data.push_back( token );
      m_parameter_table.push_back( token );
      PeekToken();
      token = m_peek_token;
      if ( strcmp( token.token.c_str(), "[" ) == 0 ) {
        GetToken( token );
        getToken_in_squareBrackets = true;
        PeekToken();
        token = m_peek_token;
        if ( strcmp( token.type.c_str(), "CONSTANT" ) == 0 ) {
          GetToken( token );
          PeekToken();
          token = m_peek_token;
          if ( strcmp( token.token.c_str(), "]" ) == 0 ) {
            GetToken( token );  
          } // if
            
          else correct = false;
          
        } // if
        
        else correct = false;
        
      } // if
      
      while ( strcmp( token.token.c_str(), "," ) == 0 ) {
        GetToken( token );
        getToken_in_squareBrackets = true;
        Is_Type_specifier( type_specifier_Correct, type_specifier_Is_Get );
        if ( type_specifier_Correct == true ) {
          PeekToken();
          token = m_peek_token;
          if ( strcmp( token.token.c_str(), "&" ) == 0 ) {
            GetToken( token );
          } // if
          
          PeekToken();
          token = m_peek_token;
          if ( strcmp( token.type.c_str(), "IDE" ) == 0 ) {
            GetToken( token );
            PeekToken();
            token = m_peek_token;
            if ( strcmp( token.token.c_str(), "[" ) == 0 ) {
              GetToken( token );
              PeekToken();
              token = m_peek_token;
              if ( strcmp( token.type.c_str(), "CONSTANT" ) == 0 ) {
                GetToken( token );
                PeekToken();
                token = m_peek_token;
                if ( strcmp( token.token.c_str(), "]" ) == 0 ) {
                  GetToken( token );
                  PeekToken();
                  token = m_peek_token;
                  if ( m_IsEOF == true ) {
                    correct = true;
                  } // if
                  
                } // if
                
                else correct = false;
                
              } // if
              
              else correct = false;
              
            } // if
            
          } // if
          
          else correct = false;
          
        } // if
        
        else correct = false;
        
      } // while
      
      
      
    } // if
    
    else correct = false;
    
  } // if
  
  else if ( type_specifier_Correct == false && type_specifier_Is_Get == true ) {
    correct = false;
  } // else if
  
  else {
    correct = false;
    Is_Get = false;
  } // else
  
  
} // Project::Is_Formal_parameter_list()

// Complete function, 2ok!
void Project::Is_Compound_statement( bool & correct, bool & Is_Get ) {
  Token token;
  bool finish = false;
  bool unexpected_error = false;
  bool declaration_Correct = false;
  bool declaration_Is_Get = true;
  bool statement_Correct = false;
  bool statement_Is_Get = true;
  bool is_in_function = true;
  PeekToken();
  token = m_peek_token;
  if ( strcmp( token.token.c_str(), "{" ) == 0 ) {
    GetToken( token );
    if ( m_function == false ) {
      m_compoundStatement = true;	
	} // if
	
    m_space_num = m_space_num + 2;
    m_now_parameter = true;
    while ( finish == false ) {
	  for ( int i = 0; i < m_space_num ; i++ ) {
        m_instruction_str = m_instruction_str + " ";
	  } // for
	  
      Is_Declaration( declaration_Correct, declaration_Is_Get );
      if ( declaration_Correct == true ) {
	    ;
      } // if
      
      else {
        if ( declaration_Correct == false && declaration_Is_Get == true ) {
          correct = false;
          finish = true;
          unexpected_error = true;
        } // if
        
        else {
          Is_Statement( statement_Correct, statement_Is_Get );
          if ( statement_Correct == true ) {
	        ;
          } // if
        
          else if ( statement_Correct == false && statement_Is_Get == true ) {
            finish = true;
            correct = false;
            unexpected_error = true;
          } // else if
          
          else {
            finish = true;
          } // else
            
        } // else
         
      } // else
       
    } // while
    
    string tmp_str = "";
    for ( int i = 0; i < m_instruction_str.size() - 2 ; i++ ) {
      tmp_str = tmp_str + m_instruction_str[i];
	} // for
	
	m_instruction_str = tmp_str;
    PeekToken();
    token = m_peek_token;
    if ( unexpected_error == false ) {
      if ( strcmp( token.token.c_str(), "}" ) == 0  ) {
      	m_space_num = m_space_num - 2;
        GetToken( token );
        correct = true; 
        m_now_parameter = false;
        if ( m_now_definition == true && m_function == false ) {
  	      m_now_definition = false;
        } // if
        
      } // if
    
      else {
        correct = false;
      } // else
        
    } // if
    
    m_compoundStatement = false;
    m_localData_table.clear();
  } // if
  
  else {
    Is_Get = false;
    correct = false;
  } // else
  
  
} // Project::Is_Compound_statement()

// Complete function, 2ok!
void Project::Is_Declaration( bool & correct, bool & Is_Get ) {
  Token token;
  Value value; 
  bool type_specifier_Correct = false;
  bool type_specifier_Is_Get = true;
  bool rest_of_declarators_Correct = false;
  bool rest_of_declarators_Is_Get = true;
  PeekToken();
  token = m_peek_token;
  Is_Type_specifier( type_specifier_Correct, type_specifier_Is_Get );
  if ( type_specifier_Correct == true ) {
    PeekToken();
    token = m_peek_token;
    if ( strcmp( token.type.c_str(), "IDE" ) == 0 ) {
      GetToken( token );
      value.token_name = token;
      if ( m_function == true )
        m_fuction_table[m_fuction_table.size()-1].data.push_back( token );
      else
        m_localData_table.push_back( value );
      m_declaration = true;
      Is_Rest_of_declarators( rest_of_declarators_Correct, rest_of_declarators_Is_Get );
      m_declaration = false;
      if ( rest_of_declarators_Correct == true ) {
        correct = true;
      } // if
      
      else correct = false;
        
    } // if
    
    else correct = false;
    
  } // if
  
  else if ( type_specifier_Correct == false && type_specifier_Is_Get == true ) {
    correct = false;
  } // else if
  
  else {
    correct = false;
    Is_Get = false;
  } // else
  
  
  
} // Project::Is_Declaration()

// Complete function, 2ok!
void Project::Is_Expression( bool & correct, bool & Is_Get, Token & value ) {
  Token token;
  Token basic_expression_value1, basic_expression_value2;
  bool finish = false;
  bool basic_expression_Correct = false;
  bool basic_expression_Is_Get = true;
  Is_Basic_expression( basic_expression_Correct, basic_expression_Is_Get, basic_expression_value1 );
  if ( basic_expression_Correct == true ) {
  	value = basic_expression_value1;
    PeekToken();
    token = m_peek_token;
    correct = true;
    if ( strcmp( token.token.c_str(), "," ) == 0 ) {
      while ( finish == false ) {
        GetToken( token );
        Is_Basic_expression( basic_expression_Correct, basic_expression_Is_Get, basic_expression_value2 );
        if ( basic_expression_Correct == false ) {
          finish = true;
          correct = false;
        } // if
      
        else {
          value = basic_expression_value2;
          PeekToken();
          token = m_peek_token;
          if ( m_IsEOF == true ) {
            correct = true;
            finish = true;
          } // if
          
          else if ( strcmp( token.token.c_str(), "," ) != 0 ) {
            finish = true;
          } // else if
            
        } // else 
      
      } // while
        
    } // if
    
  } // if
  
  else if ( basic_expression_Correct == false && basic_expression_Is_Get == true ) {
    correct = false;
  } // else if
  
  else {
    correct = false;
    Is_Get = false;
  } // else
  
} // Project::Is_Expression()

// Complete function, 2ok!
void Project::Is_Basic_expression( bool & correct, bool & Is_Get, Token & value ) {
  Token token;
  Token expression_value1;
  Token sign_value1 ;
  string exp = "";
  sign_value1.token = "";
  Token signed_unary_exp_value1;
  Token romce_and_romloe_value1;
  Token rest_of_Identifier_started_basic_exp_value1;
  Token rest_of_PPMM_Ide_star_bas_exp_value1;
  bool rest_of_Ide_star_bas_exp_Correct = false;
  bool rest_of_Ide_star_bas_exp_Is_Get = true;
  bool rest_of_PPMM_Ide_star_bas_exp_Correct = false;
  bool rest_of_PPMM_Ide_star_bas_exp_Is_Get = true;
  bool signed_unary_exp_Correct = false;
  bool signed_unary_exp_Is_Get = true;
  bool romce_and_romloe_Correct = false;
  bool romce_and_romloe_Is_Get = true;
  bool sign_Correct = false;
  bool sign_Is_Get = true;
  bool expression_Correct = false;
  bool expression_Is_Get = true;
  bool finish = false;
  bool ide_exist = false;
  bool parameter_exist = false;
  bool functData_exist = false;
  bool localData_exist = false;
  bool function_exist = false;
  bool is_MM = false;
  bool is_PP = false;
  PeekToken();
  token = m_peek_token;
  if ( strcmp( token.type.c_str(), "IDE" ) == 0 ) {
    if ( strcmp( token.token.c_str(), "Done" ) == 0 ) {
      m_is_Done = true;
    } // if
    
    if ( strcmp( token.token.c_str(), "ListAllFunctions" ) == 0 ) {
      m_ListAllFunctions = true;
    } // if
    
    if ( strcmp( token.token.c_str(), "ListFunction" ) == 0 ) {
      m_ListFunction = true;
    } // if
    
    if ( strcmp( token.token.c_str(), "ListAllVariables" ) == 0 ) {
      m_ListAllVariables = true;
    } // if
    
    if ( strcmp( token.token.c_str(), "ListVariable" ) == 0 ) {
      m_ListVariable = true;
    } // if

    
    if ( m_now_definition == false ) {
      for ( int i = 0; i < m_fuction_table.size() ; i++ ) {
        if ( strcmp( token.token.c_str(), m_fuction_table[i].token.c_str() ) == 0  ) {
          function_exist = true;
        } // if
      
      } // for
      
      
      for ( int i = 0; i < m_define_table.size() ; i++ ) {
        if ( strcmp( token.token.c_str(), m_define_table[i].token_name.token.c_str() ) == 0  ) {
          ide_exist = true;
        } // if
      
      } // for
        
    } // if
    
    else if ( m_now_definition == true && m_function == false ) {
      for ( int i = 0; i < m_define_table.size() ; i++ ) {
        if ( strcmp( token.token.c_str(), m_define_table[i].token_name.token.c_str() ) == 0  ) {
          ide_exist = true;
        } // if
      
      } // for
      
      for ( int i = 0; i < m_fuction_table.size() ; i++ ) {
        if ( strcmp( token.token.c_str(), m_fuction_table[i].token.c_str() ) == 0  ) {
          function_exist = true;
        } // if
      
      } // for
      
      for ( int i = 0; i < m_localData_table.size() ; i++ ) {
        if ( strcmp( token.token.c_str(), m_localData_table[i].token_name.token.c_str() ) == 0  ) {
          localData_exist = true;
        } // if
      
      } // for
      
      
      
	} // else if
    
    else {
      for ( int i = 0; i < m_define_table.size() ; i++ ) {
        if ( strcmp( token.token.c_str(), m_define_table[i].token_name.token.c_str() ) == 0  ) {
          ide_exist = true;
        } // if
      
      } // for
      
      for ( int i = 0; i < m_fuction_table.size() ; i++ ) {
        if ( strcmp( token.token.c_str(), m_fuction_table[i].token.c_str() ) == 0  ) {
          function_exist = true;
        } // if
      
      } // for
       
      for ( int i = 0; i < m_fuction_table[m_fuction_table.size()-1].data.size() ; i++ ) {
        if ( strcmp( token.token.c_str(), 
                     m_fuction_table[m_fuction_table.size()-1].data[i].token.c_str() ) == 0  ) {
          functData_exist = true;
        } // if
      
      } // for
      
      
    } // else
    
    if ( ide_exist == true || function_exist == true || functData_exist == true || 
	     localData_exist == true ) {
      GetToken( token );
      m_PP_token = token;
      m_MM_token = token;
      rest_of_Identifier_started_basic_exp_value1 = token;
      Is_Rest_of_Identifier_started_basic_exp( rest_of_Ide_star_bas_exp_Correct, 
                                               rest_of_Ide_star_bas_exp_Is_Get,
											   rest_of_Identifier_started_basic_exp_value1 );
      if ( rest_of_Ide_star_bas_exp_Correct == true ) {
        // PeekToken();
        // token = m_peek_token;
        value = rest_of_Identifier_started_basic_exp_value1;
        correct = true;
      } // if
    
      else correct = false;
      
    } // if
    
    
    else {
      m_undefined_ide = true;
      correct = false;
    } // else
    
  } // if
  
  else if ( strcmp( token.token.c_str(), "++" ) == 0 || strcmp( token.token.c_str(), "--" ) == 0 ) {
    GetToken( token );
    exp = token.token;
	
    PeekToken();
    token = m_peek_token;
    if ( strcmp( token.type.c_str(), "IDE" ) == 0 ) {
      GetToken( token );
      value = token;
      rest_of_PPMM_Ide_star_bas_exp_value1 = token;
      // cout << "++++++++ " << token.token << "\n";
      Is_Rest_of_PPMM_Identifier_started_basic_exp( rest_of_PPMM_Ide_star_bas_exp_Correct,
                                                    rest_of_PPMM_Ide_star_bas_exp_Is_Get,
													rest_of_PPMM_Ide_star_bas_exp_value1,
													exp );
      if ( rest_of_PPMM_Ide_star_bas_exp_Correct == true ) {
      	value = rest_of_PPMM_Ide_star_bas_exp_value1;
      	// if ( is_PP == true ) {
      	//  Do_First_PP( token );
      	//  is_PP = false;
	    // } // if
	  
        // else if ( is_MM == true ) {
        //  Do_First_MM( token );
      	//  is_MM = false;
	    // } // else if
      	
      	
        correct = true; 
      } // if
      
      else correct = false;
      
    } // if
    
    else correct = false;
    
  } // else if
  
  else if ( strcmp( token.type.c_str(), "CONSTANT" ) == 0 || 
            strcmp( token.token.c_str(), "(" ) == 0 ) 
  {
    if ( strcmp( token.type.c_str(), "CONSTANT" ) == 0 ) {
      GetToken( token );
      SetType( token );
      value = token;
      if ( m_ListFunction == true )
        m_select_funct = token.token;
      
      if ( m_ListVariable == true )
        m_select_funct = token.token;
        
      romce_and_romloe_value1 = value;
      Is_Rest_of_maybe_conditional_exp_and_rest_of_maybe_logical_OR_exp( romce_and_romloe_Correct, 
                                                                         romce_and_romloe_Is_Get,
																		 romce_and_romloe_value1 );
      if ( romce_and_romloe_Correct == true ) {
      	value = romce_and_romloe_value1;
        correct = true; 
      } // if
      
      else correct = false;
      
    } // if
    
    else if ( strcmp( token.token.c_str(), "(" ) == 0 ) {
      GetToken( token );
      Is_Expression( expression_Correct, expression_Is_Get, expression_value1 );
      if ( expression_Correct == true ) {
      	value = expression_value1;
        PeekToken();
        token = m_peek_token;
        if ( strcmp( token.token.c_str(), ")" ) == 0 ) {
          GetToken( token );
          romce_and_romloe_value1 = value;
          Is_Rest_of_maybe_conditional_exp_and_rest_of_maybe_logical_OR_exp( romce_and_romloe_Correct, 
                                                                             romce_and_romloe_Is_Get,
																			 romce_and_romloe_value1 );
          if ( romce_and_romloe_Correct == true ) {
          	value = romce_and_romloe_value1;
            correct = true; 
          } // if
      
          else correct = false;
          
        } // if
        
        else correct = false;
        
      } // if
      
      else correct = false;
      
    } // else if
                
  } // else if
  
  else {
    Is_Sign( sign_Correct, sign_Is_Get, sign_value1 );
    if ( sign_Correct == true ) {
      while ( finish == false ) {
        Is_Sign( sign_Correct, sign_Is_Get, sign_value1 );
        if ( sign_Correct == false ) {
          finish = true;
        } // if
        
      } // while
      
      Is_Signed_unary_exp( signed_unary_exp_Correct, 
	                       signed_unary_exp_Is_Get, 
						   signed_unary_exp_value1, 
						   sign_value1 );
      if ( signed_unary_exp_Correct == true ) {
      	value = signed_unary_exp_value1;
      	romce_and_romloe_value1 = value;
        Is_Rest_of_maybe_conditional_exp_and_rest_of_maybe_logical_OR_exp( romce_and_romloe_Correct, 
                                                                           romce_and_romloe_Is_Get,
																		   romce_and_romloe_value1 );
        if ( romce_and_romloe_Correct == true ) {
          value = romce_and_romloe_value1;
          correct = true;   
        } // if
        
        else correct = false;
        
      } // if 
      
      else correct = false;
      
    } // if
    
    else if ( sign_Correct == false && sign_Is_Get == true ) {
      correct = false;
    } // else if
    
    else {
      correct = false;
      Is_Get = false;
    } // else
    
  } // else

  
} // Project::Is_Basic_expression()

// Complete function, 2ok!
void Project::Is_Rest_of_Identifier_started_basic_exp( bool & correct, bool & Is_Get, Token & value ) {
  Token token;
  Token expression_value1;
  Token basic_expression_value1;
  Token romce_and_romloe_value1;
  string assignment_operator_value = "";
  bool getToken_in_squareBrackets = false;
  bool actual_parameter_list_Correct = false;
  bool actual_parameter_list_Is_Get = true;
  bool romce_and_romloe_Correct = false;
  bool romce_and_romloe_Is_Get = true;
  bool expression_Correct = false;
  bool expression_Is_Get = true;
  bool assignment_operator_Correct = false;
  bool assignment_operator_Is_Get = true;
  bool basic_expression_Correct = false;
  bool basic_expression_Is_Get = true;
  PeekToken();
  token = m_peek_token;
  if ( strcmp( token.token.c_str(), "(" ) == 0 ) {
    GetToken( token );
    Is_Actual_parameter_list( actual_parameter_list_Correct, actual_parameter_list_Is_Get );
    if ( actual_parameter_list_Correct == true ) m_is_Done = false;
    if ( actual_parameter_list_Correct == false && actual_parameter_list_Is_Get == true ) {
      correct = false;
    } // if
    
    else {
      PeekToken();
      token = m_peek_token;
      if ( strcmp( token.token.c_str(), ")" ) == 0 ) {
        GetToken( token );
        Is_Rest_of_maybe_conditional_exp_and_rest_of_maybe_logical_OR_exp( romce_and_romloe_Correct,
                                                                           romce_and_romloe_Is_Get,
																		   romce_and_romloe_value1 );
        if ( romce_and_romloe_Correct == true ) {
          correct = true;
        } // if
      
        else correct = false;
      
      } // if
    
      else {
        correct = false;
        m_is_Done = false;
      } // else
      
    } // else
    
    
  } // if
  
  else {
    m_is_Done = false;
    if ( strcmp( token.token.c_str(), "[" ) == 0 ) {
      GetToken( token );
      getToken_in_squareBrackets = true;
      Is_Expression( expression_Correct, expression_Is_Get, expression_value1 );
      if ( expression_Correct == true ) {
      	value.select_arrary_num = expression_value1.token;
      	m_PP_token.select_arrary_num = expression_value1.token;
      	m_MM_token.select_arrary_num = expression_value1.token;
        PeekToken();
        token = m_peek_token;
        if ( strcmp( token.token.c_str(), "]" ) == 0 ) {
          GetToken( token );
        } // if
      
        else correct = false;
      
      } // if   
      
      else correct = false;
    } // if
    
    Is_Assignment_operator( assignment_operator_Correct, 
	                        assignment_operator_Is_Get, 
							assignment_operator_value );
    if ( assignment_operator_Correct == true ) {
      // value.token = value.token + assignment_operator_value;
      Is_Basic_expression( basic_expression_Correct, basic_expression_Is_Get, basic_expression_value1 );
      if ( basic_expression_Correct == true ) {
      	// value.token = value.token + basic_expression_value1.token;
      	
      	// if ( strcmp( assignment_operator_value.c_str(), "=" ) == 0 ) {
      	//  SetValue( value, basic_expression_value1 );
      	//  value = basic_expression_value1;
		// } // if
		
		if ( strcmp( assignment_operator_value.c_str(), "+=" ) == 0 ||
		     strcmp( assignment_operator_value.c_str(), "-=" ) == 0 ||
			 strcmp( assignment_operator_value.c_str(), "*=" ) == 0 ||
			 strcmp( assignment_operator_value.c_str(), "/=" ) == 0 ||
			 strcmp( assignment_operator_value.c_str(), "%=" ) == 0 ||
			 strcmp( assignment_operator_value.c_str(), "=" ) == 0 ) {
		  AssignOperator( value, basic_expression_value1, assignment_operator_value );
		  // value = basic_expression_value1;
		  
		} // if
		
        correct = true;
      } // if
      
      else correct = false;
        
    } // if
    
    else if ( assignment_operator_Correct == false && assignment_operator_Is_Get == true ) {
      correct = false;
    } // else if
    
    else {
      PeekToken();
      token = m_peek_token;
      if ( strcmp( token.token.c_str(), "++" ) == 0 || strcmp( token.token.c_str(), "--" ) == 0 ) {
        GetToken( token );
        getToken_in_squareBrackets = true;
        GetValue( value );
        SetType( value );
        /*
        PeekToken();
        if ( strcmp( token.token.c_str(), "++" ) == 0 && 
			 strcmp( m_peek_token.token.c_str(), ";" ) != 0 ) {
		  Do_First_PP( value );	
		} // if
				
		else if ( strcmp( token.token.c_str(), "--" ) == 0 &&
				  strcmp( m_peek_token.token.c_str(), ";" ) != 0 ) {
          Do_First_MM( value );
		} // else if
				
				
		else if ( strcmp( token.token.c_str(), "++" ) == 0 &&
				  strcmp( m_peek_token.token.c_str(), ";" ) == 0 ) {
		  Do_Last_PP( m_PP_token );
		} // else if
                  
            // m_PP_table.push_back( m_PP_token ) ;
        else if ( strcmp( token.token.c_str(), "--" ) == 0 &&
				  strcmp( m_peek_token.token.c_str(), ";" ) == 0 ) {
          Do_Last_MM( m_MM_token );
		} // else if
        */
        
        if ( strcmp( token.token.c_str(), "++" ) == 0 )
          Do_Last_PP( m_PP_token );
        else if ( strcmp( token.token.c_str(), "--" ) == 0 )  
          Do_Last_MM( m_MM_token );
          
      } // if
      
      romce_and_romloe_value1 = value;
      Is_Rest_of_maybe_conditional_exp_and_rest_of_maybe_logical_OR_exp( romce_and_romloe_Correct, 
                                                                         romce_and_romloe_Is_Get, 
																		 romce_and_romloe_value1 );
      if ( romce_and_romloe_Correct == true ) {
      	value = romce_and_romloe_value1;
        correct = true;
      } // if
      
      else if ( romce_and_romloe_Correct == false && romce_and_romloe_Is_Get == true ) {
        correct = false;
      } // else if
      
      else {
        correct = false;
        Is_Get = false;
      } // else
      
    } // else
    
  } // else
  
  
} // Project::Is_Rest_of_Identifier_started_basic_exp() 

// Complete function, 2ok!
void Project::Is_Rest_of_PPMM_Identifier_started_basic_exp( bool & correct, 
                                                            bool & Is_Get, 
															Token & value, 
															string & exp ) {
  Token token;
  Token expression_value1;
  Token romce_and_romloe_value1;
  bool getToken_in_squareBrackets = false;
  bool expression_Correct = false;
  bool expression_Is_Get = true;
  bool romce_and_romloe_Correct = false;
  bool romce_and_romloe_Is_Get = true;
  PeekToken();
  token = m_peek_token;
  if ( strcmp( token.token.c_str(), "[" ) == 0 ) {
    GetToken( token );
    getToken_in_squareBrackets = true;
    Is_Expression( expression_Correct, expression_Is_Get, expression_value1 );
    if ( expression_Correct == true ) {
      value.select_arrary_num = expression_value1.token;
      if ( strcmp( exp.c_str(), "++" ) == 0 ) {
      	Do_First_PP( value );
      } // if
      
      if ( strcmp( exp.c_str(), "--" ) == 0 ) {
      	Do_First_PP( value );
      } // if

      
      PeekToken();
      token = m_peek_token;
      if ( strcmp( token.token.c_str(), "]" ) == 0 ) {
        GetToken( token );
      } // if
      
      else correct = false;
      
    } // if
    
    else correct = false;
    
  } // if
  
  else {
  	if ( strcmp( exp.c_str(), "++" ) == 0 ) {
      Do_First_PP( value );
    } // if
      
    if ( strcmp( exp.c_str(), "--" ) == 0 ) {
      Do_First_PP( value );
    } // if
    
  } // else
  
  romce_and_romloe_value1 = value;
  Is_Rest_of_maybe_conditional_exp_and_rest_of_maybe_logical_OR_exp( romce_and_romloe_Correct, 
                                                                     romce_and_romloe_Is_Get,
																	 romce_and_romloe_value1 );
  if ( romce_and_romloe_Correct == true ) {
  	value = romce_and_romloe_value1;
    correct = true;
  } // if
  
  else if ( romce_and_romloe_Correct == false && romce_and_romloe_Is_Get == true ) {
    correct = false;
  } // else if
  
  else {
    correct = false;
    if ( getToken_in_squareBrackets == false )
      Is_Get = false;
  } // else 
  
} // Project::Is_Rest_of_PPMM_Identifier_started_basic_exp()

// Complete function, 2ok!
void Project::Is_Signed_unary_exp( bool & correct, bool & Is_Get, Token & value, Token & sign ) {
  Token token;
  Token expression_value1;
  bool ide_exist = false;
  bool parameter_exist = false;
  bool function_exist = false;
  bool localData_exist = false;
  bool functData_exist = false;
  bool actual_parameter_list_Correct = false;
  bool actual_parameter_list_Is_Get = true;
  bool expression_Correct = false;
  bool expression_Is_Get = true;
  PeekToken();
  token = m_peek_token;
  if ( strcmp( token.type.c_str(), "IDE" ) == 0 ) {
    if ( m_now_definition == false ) {
      for ( int i = 0; i < m_fuction_table.size() ; i++ ) {
        if ( strcmp( token.token.c_str(), m_fuction_table[i].token.c_str() ) == 0  ) {
          function_exist = true;
        } // if
      
      } // for
        
      for ( int i = 0; i < m_define_table.size() ; i++ ) {
        if ( strcmp( token.token.c_str(), m_define_table[i].token_name.token.c_str() ) == 0  ) {
          ide_exist = true;
        } // if
      
      } // for
        
    } // if
    
    else if ( m_now_definition == true && m_function == false ) {
      for ( int i = 0; i < m_define_table.size() ; i++ ) {
        if ( strcmp( token.token.c_str(), m_define_table[i].token_name.token.c_str() ) == 0  ) {
          ide_exist = true;
        } // if
      
      } // for	
    	
      for ( int i = 0; i < m_fuction_table.size() ; i++ ) {
        if ( strcmp( token.token.c_str(), m_fuction_table[i].token.c_str() ) == 0  ) {
          function_exist = true;
        } // if
      
      } // for
      
      for ( int i = 0; i < m_localData_table.size() ; i++ ) {
        if ( strcmp( token.token.c_str(), m_localData_table[i].token_name.token.c_str() ) == 0  ) {
          localData_exist = true;
        } // if
      
      } // for

	} // else if
    
    else {
      for ( int i = 0; i < m_define_table.size() ; i++ ) {
        if ( strcmp( token.token.c_str(), m_define_table[i].token_name.token.c_str() ) == 0  ) {
          ide_exist = true;
        } // if
      
      } // for	
    	
      for ( int i = 0; i < m_fuction_table.size() ; i++ ) {
        if ( strcmp( token.token.c_str(), m_fuction_table[i].token.c_str() ) == 0  ) {
          function_exist = true;
        } // if
      
      } // for
       
      for ( int i = 0; i < m_fuction_table[m_fuction_table.size()-1].data.size() ; i++ ) {
        if ( strcmp( token.token.c_str(), m_fuction_table[m_fuction_table.size()-1].data[i].token.c_str() ) 
             == 0 
           ) {
          functData_exist = true;
        } // if
      
      } // for  
      
      
    } // else
    
    
    if ( ide_exist == false && parameter_exist == false && functData_exist == false &&
	     localData_exist == false ) {
      // GetToken( token );
      // Skip_Line();
      m_undefined_ide = true;
      correct = false;
    } // if
    
    else {
      GetToken( token );
      value = token;
      PeekToken();
      if ( strcmp( m_peek_token.token.c_str(), "[" ) != 0 ) {
      	GetValue( token );
      	SetType( token );
      	Sign_Value( token, sign );
      	value = token;
      	token = m_peek_token;
	  } // if
      
      else token = m_peek_token;
      // GetValue( token );
      // SetType( token );
      // Sign_Value( token, sign );
      // value = token;
      // value.sign = sign.token;
      // PeekToken();
      // token = m_peek_token;
      correct = true;
      if ( strcmp( token.token.c_str(), "(" ) == 0 || 
           strcmp( token.token.c_str(), "[" ) == 0 ) 
      {
        if ( strcmp( token.token.c_str(), "(" ) == 0 ) {
          GetToken( token );
          Is_Actual_parameter_list( actual_parameter_list_Correct, actual_parameter_list_Is_Get );
          if ( actual_parameter_list_Correct == false && actual_parameter_list_Is_Get == true ) {
            correct = false;
          } // if
          
          else {
            PeekToken();
            token = m_peek_token;
            if ( strcmp( token.token.c_str(), ")" ) == 0 ) {
              GetToken( token );
            } // if
      
            else correct = false;
                    
          } // else
        
        } // if
      
        else if ( strcmp( token.token.c_str(), "[" ) == 0 ) {
          GetToken( token );
          Is_Expression( expression_Correct, expression_Is_Get, expression_value1 );
          if ( expression_Correct == true ) {
          	value.select_arrary_num = expression_value1.token;
          	GetValue( value );
          	SetType( value );
          	Sign_Value( value, sign );
          	
            PeekToken();
            token = m_peek_token;
            if ( strcmp( token.token.c_str(), "]" ) == 0 ) {
              GetToken( token );
            } // if
        
            else correct = false;
        
          } // if
      
          else correct = false;
      
        } // else if  
      
      } // if
      
    } // else 
    
  } // if
  
  else if ( strcmp( token.type.c_str(), "CONSTANT" ) == 0 ) {
    GetToken( token );
    SetType( token );
    Sign_Value( token, sign );
    // cout << token.token;
    value = token;
    /*
    if ( strcmp( sign.token.c_str(), "+" ) == 0 ) {
      value = token;
	} // if
	
	else if ( strcmp( sign.token.c_str(), "-" ) == 0 ) {
	  value = token;
	  value.token = "-" + token.token;
	} // else if
	*/
	
    correct = true;
  } // else if
  
  else if ( strcmp( token.token.c_str(), "(" ) == 0 ) {
    GetToken( token );
    Is_Expression( expression_Correct, expression_Is_Get, expression_value1 );
    if ( expression_Correct == true ) {
      value = expression_value1;
      Sign_Value( value, sign );
      PeekToken();
      token = m_peek_token;
      if ( strcmp( token.token.c_str(), ")" ) == 0 ) {
        GetToken( token );
        correct = true; 
      } // if
      
      else correct = false;
      
    } // if
    
    else correct = false;
    
  } // else if
  
  else {
    correct = false;
    Is_Get = false;
  } // else
  
} // Project::Is_Signed_unary_exp()

// Complete function, 2ok!
void Project::Is_Assignment_operator( bool & correct, bool & Is_Get, string & value ) {
  Token token;
  PeekToken();
  token = m_peek_token;
  if ( strcmp( token.token.c_str(), "=" ) == 0 ) {
    GetToken( token );
    value = token.token;
    correct = true;
  } // if
  
  // TE
  else if ( strcmp( token.token.c_str(), "*=" ) == 0 ) {
    GetToken( token );
    value = token.token;
    correct = true;
  } // else if
  
  // DE
  else if ( strcmp( token.token.c_str(), "/=" ) == 0 ) {
    GetToken( token );
    value = token.token;
    correct = true;
  } // else if
  
  // RE
  else if ( strcmp( token.token.c_str(), "%=" ) == 0 ) {
    GetToken( token );
    value = token.token;
    correct = true;
  } // else if
  
  // PE
  else if ( strcmp( token.token.c_str(), "+=" ) == 0 ) {
    GetToken( token );
    value = token.token;
    correct = true;
  } // else if
  
  // ME
  else if ( strcmp( token.token.c_str(), "-=" ) == 0 ) {
    GetToken( token );
    value = token.token;
    correct = true;
  } // else if
  
  else {
    correct = false;
    Is_Get = false;
  } // else
  
} // Project::Is_Assignment_operator()

// Complete function, 2ok!
void Project::Is_Actual_parameter_list( bool & correct, bool & Is_Get ) {
  Token token;
  Token basic_expression_value1, basic_expression_value2;
  bool finish = false;
  bool basic_expression_Correct = false;
  bool basic_expression_Is_Get = false;
  Is_Basic_expression( basic_expression_Correct, 
                       basic_expression_Is_Get, 
					   basic_expression_value1 );
  if ( basic_expression_Correct == true ) {
    PeekToken();
    token = m_peek_token;
    correct = true;
    // value = basic_expression_value1;
    if ( strcmp( token.token.c_str(), "," ) == 0 ) {
      while ( finish == false ) {
        GetToken( token );
        Is_Basic_expression( basic_expression_Correct, 
		                     basic_expression_Is_Get, 
							 basic_expression_value2 );
        if ( basic_expression_Correct == false ) {
          correct = false;
          finish = true;
        } // if
      
        else {
          PeekToken();
          token = m_peek_token;
          if ( m_IsEOF == true ) {
            correct = true;
            finish = true;
          } // if
          
          else {
            if ( strcmp( token.token.c_str(), "," ) == 0 ) {
              GetToken( token );
            } // if
            
          } // else
        
        } // else
      
      } // while
        
    } // if
    
    
  } // if
  
  else if ( basic_expression_Correct == false && basic_expression_Is_Get == true ) {
    correct = false;
  } // else if
  
  else {
    correct = false;
    Is_Get = false;
  } // else
  
    
} // Project::Is_Actual_parameter_list()

// Complete function, 2ok!
void Project::Is_Rest_of_maybe_conditional_exp_and_rest_of_maybe_logical_OR_exp( bool & correct, 
                                                                                 bool & Is_Get,
																				 Token & value ) {
  Token token;
  Token basic_expression_value1, basic_expression_value2;
  Token rest_of_maybe_logical_OR_exp_value1;
  bool shouldnot_operator = false;
  bool rest_of_maybe_logical_OR_exp_Correct = false;
  bool rest_of_maybe_logical_OR_exp_Is_Get = true;
  bool basic_expression_Correct = false;
  bool basic_expression_Is_Get = true;
  rest_of_maybe_logical_OR_exp_value1 = value;
  // cout << "1Is_Rest_of_maybe_conditional_exp_and_rest_of_maybe_logical_OR_exp ";
  // cout << rest_of_maybe_logical_OR_exp_value1.token << "\n";
  Is_Rest_of_maybe_logical_OR_exp( rest_of_maybe_logical_OR_exp_Correct, 
                                   rest_of_maybe_logical_OR_exp_Is_Get,
								   rest_of_maybe_logical_OR_exp_value1 );
  if ( rest_of_maybe_logical_OR_exp_Correct == true ) {
  	// cout << "2Is_Rest_of_maybe_conditional_exp_and_rest_of_maybe_logical_OR_exp ";
  	// cout << rest_of_maybe_logical_OR_exp_value1.token << "\n";
  	value = rest_of_maybe_logical_OR_exp_value1;
    PeekToken();
    token = m_peek_token;
    correct = true;
    // m_shouldnot_operator = false;
    if ( strcmp( token.token.c_str(), "?" ) == 0 ) {
      m_shouldnot_operator_list.push_back( shouldnot_operator );
      GetToken( token );
      if ( strcmp( value.token.c_str(), "true" ) == 0 ) {
      	m_shouldnot_operator_list[ m_shouldnot_operator_list.size() - 1 ] = false;
	  } // if
	  
	  if ( strcmp( value.token.c_str(), "false" ) == 0 ) {
      	m_shouldnot_operator_list[ m_shouldnot_operator_list.size() - 1 ] = true;
	  } // if
	  
      Is_Basic_expression( basic_expression_Correct, basic_expression_Is_Get, basic_expression_value1 );
      if ( basic_expression_Correct == true ) {
        PeekToken();
        token = m_peek_token;
        if ( strcmp( token.token.c_str(), ":" ) == 0 ) {
          GetToken( token );
          if ( strcmp( value.token.c_str(), "true" ) == 0 ) {
      	    m_shouldnot_operator_list[ m_shouldnot_operator_list.size() - 1 ] = true;
	      } // if
	      
	      if ( strcmp( value.token.c_str(), "false" ) == 0 ) {
      	    m_shouldnot_operator_list[ m_shouldnot_operator_list.size() - 1 ] = false;
	      } // if
          
          Is_Basic_expression( basic_expression_Correct, basic_expression_Is_Get, basic_expression_value2 );
          if ( basic_expression_Correct == true ) {
          	// m_shouldnot_operator = false;
            correct = true;
            if ( strcmp( value.token.c_str(), "true" ) == 0 ) {
              value = basic_expression_value1;
			} // if
			
			else if ( strcmp( value.token.c_str(), "false" ) == 0 ) {
			  value = basic_expression_value2;
			} // else if
			
          } // if
          
          else correct = false;
          
        } // if
        
        else correct = false;
        
      } // if
      
      else correct = false;
      
      m_shouldnot_operator_list.erase( m_shouldnot_operator_list.end() ) ;
      
    } // if

    // m_shouldnot_operator = false;
    
  } // if
  
  else if ( rest_of_maybe_logical_OR_exp_Correct == false && rest_of_maybe_logical_OR_exp_Is_Get == true ) {
    correct = false;
  } // else if
  
  else {
    correct = false;
    Is_Get = false;
  } // else
  
  
  
} // Project::Is_Rest_of_maybe_conditional_exp_and_rest_of_maybe_logical_OR_exp()

// Complete function, 2ok!
void Project::Is_Rest_of_maybe_logical_OR_exp( bool & correct, bool & Is_Get, Token & value ) {
  string exp = "";
  Token token;
  Token rest_of_maybe_logical_AND_exp_value1;
  Token maybe_logical_AND_exp_value1;
  bool finish = false;
  bool rest_of_maybe_logical_AND_exp_Correct = false;
  bool rest_of_maybe_logical_AND_exp_Is_Get = true;
  bool maybe_logical_AND_exp_Correct = false;
  bool maybe_logical_AND_exp_Is_Get = true;
  rest_of_maybe_logical_AND_exp_value1 = value;
  // cout << "1Rest_of_maybe_logical_OR_exp " << rest_of_maybe_logical_AND_exp_value1.token << "\n";
  Is_Rest_of_maybe_logical_AND_exp( rest_of_maybe_logical_AND_exp_Correct, 
                                    rest_of_maybe_logical_AND_exp_Is_Get,
									rest_of_maybe_logical_AND_exp_value1 );
  if ( rest_of_maybe_logical_AND_exp_Correct == true ) {
  	// cout << "2Rest_of_maybe_logical_OR_exp " << rest_of_maybe_logical_AND_exp_value1.token << "\n";
  	value = rest_of_maybe_logical_AND_exp_value1;
    PeekToken();
    token = m_peek_token;
    correct = true;
    if ( strcmp( token.token.c_str(), "||" ) == 0 ) {
      while ( finish == false ) {
        GetToken( token );
        exp = token.token;
        Is_Maybe_logical_AND_exp( maybe_logical_AND_exp_Correct, 
		                          maybe_logical_AND_exp_Is_Get, 
								  maybe_logical_AND_exp_value1 );
        if ( maybe_logical_AND_exp_Correct == false ) {
          correct = false;
          finish = true;
        } // if
      
        else {
          if ( m_IsEOF == true ) {
            correct = true;
            finish = true;
          } // if
            
            
          else {
          	if ( strcmp( exp.c_str(), "||" ) == 0 ) {
          	  if ( strcmp( rest_of_maybe_logical_AND_exp_value1.type.c_str(), "IDE" ) == 0 ) 
          	    GetValue( rest_of_maybe_logical_AND_exp_value1 );
          	  if ( strcmp( maybe_logical_AND_exp_value1.type.c_str(), "IDE" ) == 0 ) 
          	    GetValue( maybe_logical_AND_exp_value1 );
          	    
          	  // cout << rest_of_maybe_logical_AND_exp_value1.token << "\n";
          	  // cout << maybe_logical_AND_exp_value1.token << "\n";
          	  Operator( rest_of_maybe_logical_AND_exp_value1, maybe_logical_AND_exp_value1, exp ) ;	
          	  value = rest_of_maybe_logical_AND_exp_value1;
			} // if
          	
          	PeekToken();
            token = m_peek_token; 
            if ( strcmp( token.token.c_str(), "||" ) != 0 ) {
              correct = true;
              finish = true;
            } // if
            
		  } // else
          
        } // else
        
      } // while
      
    } // if
    
  } // if
  
  else if ( rest_of_maybe_logical_AND_exp_Correct == false 
            && rest_of_maybe_logical_AND_exp_Is_Get == true ) {
    correct = false;
  } // else if
  
  else {
    correct = false;
    Is_Get = false;
  } // else
  
} // Project::Is_Rest_of_maybe_logical_OR_exp()

// Complete function, 2ok!
void Project::Is_Rest_of_maybe_logical_AND_exp( bool & correct, bool & Is_Get, Token & value ) {
  string exp = "";
  Token token ;
  Token rest_of_maybe_bit_OR_exp_value1;
  Token maybe_bit_OR_exp_value1;
  bool finish = false;
  bool rest_of_maybe_bit_OR_exp_Correct = false;
  bool rest_of_maybe_bit_OR_exp_Is_Get = true;
  bool maybe_bit_OR_exp_Correct = false;
  bool maybe_bit_OR_exp_Is_Get = true;
  rest_of_maybe_bit_OR_exp_value1 = value;
  // cout << "1Rest_of_maybe_logical_AND_exp " << rest_of_maybe_bit_OR_exp_value1.token << "\n";
  Is_Rest_of_maybe_bit_OR_exp( rest_of_maybe_bit_OR_exp_Correct, 
                               rest_of_maybe_bit_OR_exp_Is_Get,
                               rest_of_maybe_bit_OR_exp_value1 );
  if ( rest_of_maybe_bit_OR_exp_Correct == true ) {
  	// cout << "2Rest_of_maybe_logical_AND_exp " << rest_of_maybe_bit_OR_exp_value1.token << "\n";
  	value = rest_of_maybe_bit_OR_exp_value1;
    PeekToken();
    token = m_peek_token;
    correct = true;
    if ( strcmp( token.token.c_str(), "&&" ) == 0 ) {
      while ( finish == false ) {
        GetToken( token );
        exp = token.token;
        Is_Maybe_bit_OR_exp( maybe_bit_OR_exp_Correct, maybe_bit_OR_exp_Is_Get, maybe_bit_OR_exp_value1 );
        if ( maybe_bit_OR_exp_Correct == false ) {
          correct = false;
          finish = true;
        } // if
      
        else {
          if ( m_IsEOF == true ) {
            correct = true;
            finish = true;
          } // if
        
          else {
          	if ( strcmp( exp.c_str(), "&&" ) == 0 ) {
          	  GetValue( rest_of_maybe_bit_OR_exp_value1 );
          	  GetValue( maybe_bit_OR_exp_value1 );  
          	  Operator( rest_of_maybe_bit_OR_exp_value1, maybe_bit_OR_exp_value1, exp ) ;	
          	  value = rest_of_maybe_bit_OR_exp_value1;
			} // if
			
          	
            PeekToken();
            token = m_peek_token;
            if ( strcmp( token.token.c_str(), "&&" ) != 0 ) {
              correct = true;
              finish = true;
            } // if
            
          } // else
          
        } // else
      
      } // while
      
    } // if
    
  } // if
    
  else if ( rest_of_maybe_bit_OR_exp_Correct == false && rest_of_maybe_bit_OR_exp_Is_Get == true ) {
    correct = false;
  } // else if
  
  else {
    correct = false;
    Is_Get = false;
  } // else
    
} // Project::Is_Rest_of_maybe_logical_AND_exp()

// Complete function, 2ok!
void Project::Is_Maybe_logical_AND_exp( bool & correct, bool & Is_Get, Token & value ) {
  string exp = "";
  Token token;
  Token maybe_bit_OR_exp_value1, maybe_bit_OR_exp_value2;
  bool finish = false;
  bool maybe_bit_OR_exp_Correct = false;
  bool maybe_bit_OR_exp_Is_Get = true;
  Is_Maybe_bit_OR_exp( maybe_bit_OR_exp_Correct, maybe_bit_OR_exp_Is_Get, maybe_bit_OR_exp_value1 );
  if ( maybe_bit_OR_exp_Correct == true ) {
    PeekToken();
    token = m_peek_token;
    correct = true;
    value = maybe_bit_OR_exp_value1;
    if ( strcmp( token.token.c_str(), "&&" ) == 0 ) {
      while ( finish == false ) {
        GetToken( token );
        exp = token.token;
        Is_Maybe_bit_OR_exp( maybe_bit_OR_exp_Correct, 
		                     maybe_bit_OR_exp_Is_Get, 
							 maybe_bit_OR_exp_value2 );
        if ( maybe_bit_OR_exp_Correct == false ) {
          correct = false;
          finish = true;
        } // if
      
        else {        
          if ( m_IsEOF == true ) {
            correct = true;
            finish = true;
          } // if
          
          else {
          	if ( strcmp( exp.c_str(), "&&" ) == 0 ) {
          	  GetValue( maybe_bit_OR_exp_value1 );
          	  GetValue( maybe_bit_OR_exp_value2 );
          	  Operator( maybe_bit_OR_exp_value1, maybe_bit_OR_exp_value2, exp ) ;	
          	  value = maybe_bit_OR_exp_value1;
			} // if
          	
          	
          	
          	PeekToken();
            token = m_peek_token;
            if ( strcmp( token.token.c_str(), "&&" ) != 0 ) {
              correct = true;
              finish = true;
            } // if
            
		  } // else
        
        } // else
      
      } // while
      
    } // if
    
  } // if
  
  else if ( maybe_bit_OR_exp_Correct == false && maybe_bit_OR_exp_Is_Get == true ) {
    correct = false;
  } // else if
  
  else {
    correct = false;
    Is_Get = false;
  } // else
  
} // Project::Is_Maybe_logical_AND_exp()

// Complete function, 2ok!
void Project::Is_Rest_of_maybe_bit_OR_exp( bool & correct, bool & Is_Get, Token & value ) {
  Token token;
  Token rest_of_maybe_bit_ex_OR_exp_value1;
  Token maybe_bit_ex_OR_exp_value1;
  bool finish = false;
  bool rest_of_maybe_bit_ex_OR_exp_Correct = false;
  bool rest_of_maybe_bit_ex_OR_exp_Is_Get = true;
  bool maybe_bit_ex_OR_exp_Correct = false;
  bool maybe_bit_ex_OR_exp_Is_Get = true;
  rest_of_maybe_bit_ex_OR_exp_value1 = value;
  // cout << "1Rest_of_maybe_bit_OR_exp " << rest_of_maybe_bit_ex_OR_exp_value1.token << "\n";
  Is_Rest_of_maybe_bit_ex_OR_exp( rest_of_maybe_bit_ex_OR_exp_Correct, 
                                  rest_of_maybe_bit_ex_OR_exp_Is_Get,
								  rest_of_maybe_bit_ex_OR_exp_value1 );
  if ( rest_of_maybe_bit_ex_OR_exp_Correct == true ) {
  	// cout << "2Rest_of_maybe_bit_OR_exp " << rest_of_maybe_bit_ex_OR_exp_value1.token << "\n";
  	value = rest_of_maybe_bit_ex_OR_exp_value1;
    PeekToken();
    token = m_peek_token;
    correct = true;
    if ( strcmp( token.token.c_str(), "|" ) == 0 ) {
      while ( finish == false ) {
        GetToken( token );
        Is_Maybe_bit_ex_OR_exp( maybe_bit_ex_OR_exp_Correct, 
		                        maybe_bit_ex_OR_exp_Is_Get, 
								maybe_bit_ex_OR_exp_value1 );
        if ( maybe_bit_ex_OR_exp_Correct == false ) {
          correct = false;
          finish = true;
        } // if
      
        else {
          if ( m_IsEOF == true ) {
            correct = true;
            finish = true;
          } // if
          
          else {
            PeekToken();
            token = m_peek_token;
            if ( strcmp( token.token.c_str(), "|" ) != 0 ) {
              correct = true;
              finish = true;
            } // if
            
          } // else
        
        } // else
      
      } // while
      
    } // if
    
  } // if
  
  else if ( rest_of_maybe_bit_ex_OR_exp_Correct == false && rest_of_maybe_bit_ex_OR_exp_Is_Get == true ) {
    correct = false;
  } // else if
  
  else {
    correct = false;
    Is_Get = false;
  } // else
  
} // Project::Is_Rest_of_maybe_bit_OR_exp()

// Complete function, 2ok!
void Project::Is_Maybe_bit_OR_exp( bool & correct, bool & Is_Get, Token & value ) {
  Token token;
  Token maybe_bit_ex_OR_exp_value1, maybe_bit_ex_OR_exp_value2;
  bool finish = false;
  bool maybe_bit_ex_OR_exp_Correct = false;
  bool maybe_bit_ex_OR_exp_Is_Get = true;
  Is_Maybe_bit_ex_OR_exp( maybe_bit_ex_OR_exp_Correct, 
                          maybe_bit_ex_OR_exp_Is_Get, 
						  maybe_bit_ex_OR_exp_value1 );
  if ( maybe_bit_ex_OR_exp_Correct == true ) {
    PeekToken();
    token = m_peek_token;
    correct = true;
    value = maybe_bit_ex_OR_exp_value1;
    if ( strcmp( token.token.c_str(), "|" ) == 0 ) {
      while ( finish == false ) {
        GetToken( token );
        Is_Maybe_bit_ex_OR_exp( maybe_bit_ex_OR_exp_Correct, 
		                        maybe_bit_ex_OR_exp_Is_Get, 
								maybe_bit_ex_OR_exp_value2 );
        if ( maybe_bit_ex_OR_exp_Correct == false ) {
          correct = false;
          finish = true;
        } // if
      
        else {
          if ( m_IsEOF == true ) {
            correct = true;
            finish = true;
          } // if
          
          else {
            PeekToken();
            token = m_peek_token;
            if ( strcmp( token.token.c_str(), "|" ) != 0 ) {
              correct = true;
              finish = true;
            } // if
            
          } // else
        
        } // else
      
      
      } // while
      
    } // if
    
  } // if
  
  else if ( maybe_bit_ex_OR_exp_Correct == false && maybe_bit_ex_OR_exp_Is_Get == true ) {
    correct = false;
  } // else if
  
  else {
    correct = false;
    Is_Get = false;
  } // else
  
} // Project::Is_Maybe_bit_OR_exp()

// Complete function, 2ok!
void Project::Is_Maybe_bit_ex_OR_exp( bool & correct, bool & Is_Get, Token & value ) {
  Token token;
  Token maybe_bit_AND_exp_value1, maybe_bit_AND_exp_value2;
  bool finish = false;
  bool maybe_bit_AND_exp_Correct = false;
  bool maybe_bit_AND_exp_Is_Get = true;
  Is_Maybe_bit_AND_exp( maybe_bit_AND_exp_Correct, 
                        maybe_bit_AND_exp_Is_Get, 
						maybe_bit_AND_exp_value1 );
  if ( maybe_bit_AND_exp_Correct == true ) {
    PeekToken();
    token = m_peek_token;
    correct = true;
    value = maybe_bit_AND_exp_value1;
    if ( strcmp( token.token.c_str(), "^" ) == 0 ) {
      while ( finish == false ) {
        GetToken( token );
        Is_Maybe_bit_AND_exp( maybe_bit_AND_exp_Correct, 
		                      maybe_bit_AND_exp_Is_Get, 
							  maybe_bit_AND_exp_value2 );
        if ( maybe_bit_AND_exp_Correct == false ) {
          correct = false;
          finish = false;
        } // if
      
        else {
          if ( m_IsEOF == true ) {
            correct = true;
            finish = true;
          } // if
          
          PeekToken();
          token = m_peek_token;
          if ( strcmp( token.token.c_str(), "^" ) != 0 ) {
            correct = true;
            finish = true;
          } // if
          
        } // else
      
      } // while
      
    } // if
    
  } // if
  
  else if ( maybe_bit_AND_exp_Correct == false && maybe_bit_AND_exp_Is_Get == true ) {
    correct = false;
  } // else if
  
  else {
    correct = false;
    Is_Get = false;
  } // else
  
  
} // Project::Is_Maybe_bit_ex_OR_exp()

// Complete function, 2ok!
void Project::Is_Rest_of_maybe_bit_ex_OR_exp( bool & correct, bool & Is_Get, Token & value ) {
  Token token;
  Token maybe_bit_AND_exp_value1;
  Token rest_of_maybe_bit_AND_exp_value1;
  bool finish = false;
  bool rest_of_maybe_bit_AND_exp_Correct = false;
  bool rest_of_maybe_bit_AND_exp_Is_Get = true;
  bool maybe_bit_AND_exp_Correct = false;
  bool maybe_bit_AND_exp_Is_Get = true;
  rest_of_maybe_bit_AND_exp_value1 = value;
  // cout << "1Rest_of_maybe_bit_ex_OR_exp " << rest_of_maybe_bit_AND_exp_value1.token << "\n";
  Is_Rest_of_maybe_bit_AND_exp( rest_of_maybe_bit_AND_exp_Correct, 
                                rest_of_maybe_bit_AND_exp_Is_Get,
								rest_of_maybe_bit_AND_exp_value1 );
  if ( rest_of_maybe_bit_AND_exp_Correct == true ) {
  	// cout << "2Rest_of_maybe_bit_ex_OR_exp " << rest_of_maybe_bit_AND_exp_value1.token << "\n";
  	value = rest_of_maybe_bit_AND_exp_value1;
    PeekToken();
    token = m_peek_token;
    correct = true;
    if ( strcmp( token.token.c_str(), "^" ) == 0 ) {
      while ( finish == false ) {
        GetToken( token );
        Is_Maybe_bit_AND_exp( maybe_bit_AND_exp_Correct, 
		                      maybe_bit_AND_exp_Is_Get, 
							  maybe_bit_AND_exp_value1 );
        if ( maybe_bit_AND_exp_Correct == false ) {
          correct = false;
          finish = true;
        } // if
      
        else {
          if ( m_IsEOF == true ) {
            correct = true;
            finish = true;
          } // if
          
          else {
            PeekToken();
            token = m_peek_token;
            if ( strcmp( token.token.c_str(), "^" ) != 0 ) {
              correct = true;
              finish = true;
            } // if
            
          } // else
        
        } // else
      
      
      } // while
      
    } // if
    
  } // if
  
  else if ( rest_of_maybe_bit_AND_exp_Correct == false && rest_of_maybe_bit_AND_exp_Is_Get == true ) {
    correct = false;
  } // else if
  
  else {
    correct = false;
    Is_Get = false;
  } // else
  
} // Project::Is_Rest_of_maybe_bit_ex_OR_exp()

// Complete function, 2ok!
void Project::Is_Maybe_bit_AND_exp( bool & correct, bool & Is_Get, Token & value ) {
  string exp = "";
  Token token;
  Token maybe_equality_exp_value1;
  bool finish = false;
  bool maybe_equality_exp_Correct = false;
  bool maybe_equality_exp_Is_Get = true;
  Is_Maybe_equality_exp( maybe_equality_exp_Correct, 
                         maybe_equality_exp_Is_Get, 
						 maybe_equality_exp_value1 );
  if ( maybe_equality_exp_Correct == true ) {
    PeekToken();
    token = m_peek_token;
    value = maybe_equality_exp_value1;
    correct = true;
    if ( strcmp( token.token.c_str(), "&" ) == 0  ) {
      while ( finish == false ) {
        GetToken( token );
        Is_Maybe_equality_exp( maybe_equality_exp_Correct, 
		                       maybe_equality_exp_Is_Get, 
							   maybe_equality_exp_value1 );
        if ( maybe_equality_exp_Correct == false ) {
          correct = false;
          finish = true;
        }   // if
      
        else {
          if ( m_IsEOF == true ) {
            correct = true;
            finish = true;
          } // if
          
          else {
            PeekToken();
            token = m_peek_token;
            if ( strcmp( token.token.c_str(), "&" ) != 0  ) {
              correct = true;
              finish = true;
            } // if
            
          } // else
        
        } // else
      
      } // while
      
    } // if
    
  } // if
  
  else if ( maybe_equality_exp_Correct == false && maybe_equality_exp_Is_Get == true ) {
    correct = false;
  } // else if
  
  else {
    correct = false;
    Is_Get = false;
  } // else
  
} // Project::Is_Maybe_bit_AND_exp()

// Complete function, 2ok!
void Project::Is_Rest_of_maybe_bit_AND_exp( bool & correct, bool & Is_Get, Token & value ) {
  Token token;
  Token maybe_equality_exp_value1;
  Token rest_of_maybe_equality_exp_value1;
  bool finish = false;
  bool rest_of_maybe_equality_exp_Correct = false;
  bool rest_of_maybe_equality_exp_Is_Get = true;
  bool maybe_equality_exp_Correct = false;
  bool maybe_equality_exp_Is_Get = true;
  rest_of_maybe_equality_exp_value1 = value;
  // cout << "1Rest_of_maybe_bit_AND_exp " << rest_of_maybe_equality_exp_value1.token << "\n";
  Is_Rest_of_maybe_equality_exp( rest_of_maybe_equality_exp_Correct, 
                                 rest_of_maybe_equality_exp_Is_Get,
								 rest_of_maybe_equality_exp_value1 );
  if ( rest_of_maybe_equality_exp_Correct == true ) {
  	// cout << "2Rest_of_maybe_bit_AND_exp " << rest_of_maybe_equality_exp_value1.token << "\n";
  	value = rest_of_maybe_equality_exp_value1;
    PeekToken();
    token = m_peek_token;
    correct = true;
    if ( strcmp( token.token.c_str(), "&" ) == 0 ) {
      while ( finish == false ) {
        GetToken( token );
        Is_Maybe_equality_exp( maybe_equality_exp_Correct, 
		                       maybe_equality_exp_Is_Get, 
							   maybe_equality_exp_value1 );
        if ( maybe_equality_exp_Correct == false ) {
          correct = false;  
          finish = true;
        } // if
      
        else {
          if ( m_IsEOF == true ) {
            correct = true;
            finish = true;
          } // if
          
          else {
            PeekToken();
            token = m_peek_token;
            if ( strcmp( token.token.c_str(), "&" ) != 0 ) {
              correct = true;
              finish = true;
            } // if
            
          } // else
        
        } // else
      
      } // while
      
    } // if

  } // if
  
  else if ( rest_of_maybe_equality_exp_Correct == false && rest_of_maybe_equality_exp_Is_Get == true ) {
    correct = false;
  } // else if
  
  else {
    correct = false;
    Is_Get = false;
  } // else 
  
} // Project::Is_Rest_of_maybe_bit_AND_exp()

// Complete function, 2ok!
void Project::Is_Maybe_equality_exp( bool & correct, bool & Is_Get, Token & value ) {
  string exp = "";
  Token token;
  bool finish = false;
  Token maybe_relational_exp_value1, maybe_relational_exp_value2;
  bool maybe_relational_exp_Correct = false;
  bool maybe_relational_exp_Is_Get = true;
  Is_Maybe_relational_exp( maybe_relational_exp_Correct, 
                           maybe_relational_exp_Is_Get, 
						   maybe_relational_exp_value1 );
  if ( maybe_relational_exp_Correct == true ) {
    PeekToken();
    token = m_peek_token;
    value = maybe_relational_exp_value1;
    correct = true;
    if ( strcmp( token.token.c_str(), "==" ) == 0 || strcmp( token.token.c_str(), "!=" ) == 0 ) {
      while ( finish == false ) {
        GetToken( token );
        exp = token.token;
        Is_Maybe_relational_exp( maybe_relational_exp_Correct, 
		                         maybe_relational_exp_Is_Get, 
								 maybe_relational_exp_value2 );
        if ( maybe_relational_exp_Correct == false ) {
          correct = false;
          finish = true;
        } // if
        
        else {
          if ( m_IsEOF == true ) {
            correct = true;
            finish = true;
          } // if
          
          else {
          	if ( strcmp( exp.c_str(), "==" ) == 0 ) {
          	  if ( strcmp( maybe_relational_exp_value1.type.c_str(), "IDE" ) == 0 ) 
          	    GetValue( maybe_relational_exp_value1 );
          	  if ( strcmp( maybe_relational_exp_value2.type.c_str(), "IDE" ) == 0 ) 
          	    GetValue( maybe_relational_exp_value2 );
          	  Operator( maybe_relational_exp_value1, maybe_relational_exp_value2, "==" ) ;
          	  value = maybe_relational_exp_value1;
			  
			} // if
			
			else if ( strcmp( exp.c_str(), "!=" ) == 0 ) {
			  if ( strcmp( maybe_relational_exp_value1.type.c_str(), "IDE" ) == 0 ) 
          	    GetValue( maybe_relational_exp_value1 );
          	  if ( strcmp( maybe_relational_exp_value2.type.c_str(), "IDE" ) == 0 ) 
          	    GetValue( maybe_relational_exp_value2 );
          	  Operator( maybe_relational_exp_value1, maybe_relational_exp_value2, "!=" ) ;
          	  value = maybe_relational_exp_value1;
			  
			} // else if
			
            PeekToken();
            token = m_peek_token;
            if ( strcmp( token.token.c_str(), "==" ) != 0 && strcmp( token.token.c_str(), "!=" ) != 0 ) {
              correct = true;
              finish = true;
            } // if
            
          } // else
          
        } // else
      
      } // while
      
    } // if
    
  } // if
  
  else if ( maybe_relational_exp_Correct == false && maybe_relational_exp_Is_Get == true ) {
    correct = false;
  } // else if
  
  else {
    correct = false;
    Is_Get = false;
  } // else
  
} // Project::Is_Maybe_equality_exp()

// Complete function, 2ok!
void Project::Is_Rest_of_maybe_equality_exp( bool & correct, bool & Is_Get, Token & value ) {
  string exp = "";
  Token token;
  Token maybe_relational_exp_value1;
  Token rest_of_maybe_relational_exp_value1;
  bool finish = false;
  bool rest_of_maybe_relational_exp_Correct = false;
  bool rest_of_maybe_relational_exp_Is_Get = true;
  bool maybe_relational_exp_Correct = false;
  bool maybe_relational_exp_Is_Get = true;
  rest_of_maybe_relational_exp_value1 = value;
  // cout << "1Rest_of_maybe_equality_exp " << rest_of_maybe_relational_exp_value1.token << "\n";
  Is_Rest_of_maybe_relational_exp( rest_of_maybe_relational_exp_Correct, 
                                   rest_of_maybe_relational_exp_Is_Get,
								   rest_of_maybe_relational_exp_value1 );
  if ( rest_of_maybe_relational_exp_Correct == true ) {
  	// cout << "2Rest_of_maybe_equality_exp " << rest_of_maybe_relational_exp_value1.token << "\n";
  	value = rest_of_maybe_relational_exp_value1;
    PeekToken();
    token = m_peek_token;
    correct = true;
    if ( strcmp( token.token.c_str(), "==" ) == 0 || strcmp( token.token.c_str(), "!=" ) == 0 ) {
      while ( finish == false ) {
        GetToken( token );
        exp = token.token;
        Is_Maybe_relational_exp( maybe_relational_exp_Correct, 
		                         maybe_relational_exp_Is_Get, 
								 maybe_relational_exp_value1 );
        if ( maybe_relational_exp_Correct == false ) {
          correct = false;
          finish = true;    
        } // if
      
        else {
          if ( m_IsEOF == true ) {
            correct = true;
            finish = true;
          } // if
          
          else {
          	if ( strcmp( exp.c_str(), "==" ) == 0 ) {
          	  if ( strcmp( rest_of_maybe_relational_exp_value1.type.c_str(), "IDE" ) == 0 ) 
			    GetValue( rest_of_maybe_relational_exp_value1 );
			  if ( strcmp( maybe_relational_exp_value1.type.c_str(), "IDE" ) == 0 ) 
			    GetValue( maybe_relational_exp_value1 );
			  Operator( rest_of_maybe_relational_exp_value1, maybe_relational_exp_value1, "==" ) ;
			  value = rest_of_maybe_relational_exp_value1;
          	  
			} // if
			
			else if ( strcmp( exp.c_str(), "!=" ) == 0 ) {
			  if ( strcmp( rest_of_maybe_relational_exp_value1.type.c_str(), "IDE" ) == 0 ) 
			    GetValue( rest_of_maybe_relational_exp_value1 );
			  if ( strcmp( maybe_relational_exp_value1.type.c_str(), "IDE" ) == 0 ) 
			    GetValue( maybe_relational_exp_value1 );
			  Operator( rest_of_maybe_relational_exp_value1, maybe_relational_exp_value1, "!=" ) ;
			  value = rest_of_maybe_relational_exp_value1;
			  
			} // else if
          	
            PeekToken();
            token = m_peek_token;
            if ( strcmp( token.token.c_str(), "==" ) != 0 && strcmp( token.token.c_str(), "!=" ) != 0 ) {
              correct = true;
              finish = true;
            } // if
            
          } // else
          
        } // else
        
      } // while
      
    } // if
    
  } // if
  
  else if ( rest_of_maybe_relational_exp_Correct == false && rest_of_maybe_relational_exp_Is_Get == true ) {
    correct = false;
  } // else if
  
  else {
    correct = false;
    Is_Get = false;
  } // else
  
  
} // Project::Is_Rest_of_maybe_equality_exp()

// Complete function, 2ok!
void Project::Is_Maybe_relational_exp( bool & correct, bool & Is_Get, Token & value ) {
  string exp = "";
  Token token;
  Token maybe_shift_exp_value1, maybe_shift_exp_value2;
  bool finish = false;
  bool maybe_shift_exp_Correct = false;
  bool maybe_shift_exp_Is_Get = true;
  Is_Maybe_shift_exp( maybe_shift_exp_Correct, maybe_shift_exp_Is_Get, maybe_shift_exp_value1 );
  if ( maybe_shift_exp_Correct == true ) {
    PeekToken();
    token = m_peek_token;
    correct = true;
    value = maybe_shift_exp_value1;
    if ( strcmp( token.token.c_str(), "<" ) == 0 || strcmp( token.token.c_str(), ">" ) == 0 || 
         strcmp( token.token.c_str(), ">=" ) == 0 || strcmp( token.token.c_str(), "<=" ) == 0 ) {
      while ( finish == false ) {
        GetToken( token );
        exp = token.token;
        Is_Maybe_shift_exp( maybe_shift_exp_Correct, maybe_shift_exp_Is_Get, maybe_shift_exp_value2 );
        if ( maybe_shift_exp_Correct == false ) {
          correct = false;
          finish = true;
        } // if
      
        else {
          if ( m_IsEOF == true ) {
            correct = true;
            finish = true;
          } // if
          
          else {
          	if ( strcmp( exp.c_str(), "<" ) == 0 ) {
          	  GetValue( maybe_shift_exp_value1 );
			  GetValue( maybe_shift_exp_value2 );
          	  Operator( maybe_shift_exp_value1, maybe_shift_exp_value2, "<" );
          	  value = maybe_shift_exp_value1;
			} // if
			
			else if ( strcmp( exp.c_str(), ">" ) == 0 ) {
			  GetValue( maybe_shift_exp_value1 );
			  GetValue( maybe_shift_exp_value2 );
          	  Operator( maybe_shift_exp_value1, maybe_shift_exp_value2, ">" );
          	  value = maybe_shift_exp_value1;
			  
			} // else if
			
			else if ( strcmp( exp.c_str(), ">=" ) == 0 ) {
			  GetValue( maybe_shift_exp_value1 );
			  GetValue( maybe_shift_exp_value2 );
          	  Operator( maybe_shift_exp_value1, maybe_shift_exp_value2, ">=" );
          	  value = maybe_shift_exp_value1;
			  
			} // else if
			
			else if ( strcmp( exp.c_str(), "<=" ) == 0 ) {
			  GetValue( maybe_shift_exp_value1 );
			  GetValue( maybe_shift_exp_value2 );
          	  Operator( maybe_shift_exp_value1, maybe_shift_exp_value2, "<=" );
          	  value = maybe_shift_exp_value1;
			  
			} // else if
          	
            PeekToken();
            token = m_peek_token;
            if ( strcmp( token.token.c_str(), "<" ) != 0 && strcmp( token.token.c_str(), ">" ) != 0 && 
                 strcmp( token.token.c_str(), ">=" ) != 0 && strcmp( token.token.c_str(), "<=" ) != 0 ) {
              correct = true;
              finish = true;
            } // if
            
          } // else
        
        } // else
      
      } // while
      
    } // if
    
  } // if
  
  else if ( maybe_shift_exp_Correct == false && maybe_shift_exp_Is_Get == true ) {
    correct = false;
  } // else if
  
  else {
    correct = false;
    Is_Get = false;
  } // else 
  
} // Project::Is_Maybe_relational_exp()

// Complete function, 2ok!
void Project::Is_Maybe_shift_exp( bool & correct, bool & Is_Get, Token & value ) {
  string exp = "";
  Token token;
  Token maybe_additive_exp_value1, maybe_additive_exp_value2;
  bool finish = false;
  bool maybe_additive_exp_Correct = false;
  bool maybe_additive_exp_Is_Get = true;
  Is_Maybe_additive_exp( maybe_additive_exp_Correct, 
                         maybe_additive_exp_Is_Get, 
						 maybe_additive_exp_value1 );
  if ( maybe_additive_exp_Correct == true ) {
  	value = maybe_additive_exp_value1;
    PeekToken();
    token = m_peek_token;
    correct = true;
    if ( strcmp( token.token.c_str(), ">>" ) == 0 || strcmp( token.token.c_str(), "<<" ) == 0 ) {
      while ( finish == false ) {
        GetToken( token );
        exp = token.token;
        Is_Maybe_additive_exp( maybe_additive_exp_Correct, 
		                       maybe_additive_exp_Is_Get, 
							   maybe_additive_exp_value2 );
        if ( maybe_additive_exp_Correct == false ) {
          correct = false;
          finish = true;
        } // if
      
        else {
          if ( m_IsEOF == true ) {
            correct = true;
            finish = true;
          } // if
          
          else {
          	GetValue( maybe_additive_exp_value1 );
          	GetValue( maybe_additive_exp_value2 );  
          	if ( strcmp( exp.c_str(), ">>" ) == 0 ) {
          	  Operator( maybe_additive_exp_value1, maybe_additive_exp_value2, exp ) ;
          	  value = maybe_additive_exp_value1;
			} // if
			
			else if ( strcmp( exp.c_str(), "<<" ) == 0 ) {
          	  Operator( maybe_additive_exp_value1, maybe_additive_exp_value2, exp ) ;
          	  value = maybe_additive_exp_value1;
		    } // else if
		    
            PeekToken();
            token = m_peek_token;
            if ( strcmp( token.token.c_str(), ">>" ) != 0 && strcmp( token.token.c_str(), "<<" ) != 0 ) {
              correct = true;
              finish = true;
            } // if
            
          } // else
        
        } // else
      
      } // while
      
    } // if
    
  } // if
  
  else if ( maybe_additive_exp_Correct == false && maybe_additive_exp_Is_Get == true ) {
    correct = false;
  } // else if
  
  else {
    correct = false;
    Is_Get = false;
  } // else
  
} // Project::Is_Maybe_shift_exp()

// Complete function, 2ok!
void Project::Is_Rest_of_maybe_relational_exp( bool & correct, bool & Is_Get, Token & value ) {
  string exp = ""; 
  Token token;
  Token maybe_shift_exp_value1;
  Token rest_of_maybe_shift_exp_value1;
  bool finish = false;
  bool rest_of_maybe_shift_exp_Correct = false;
  bool rest_of_maybe_shift_exp_Is_Get = true;
  bool maybe_shift_exp_Correct = false;
  bool maybe_shift_exp_Is_Get = true;
  rest_of_maybe_shift_exp_value1 = value;
  // cout << "1Rest_of_maybe_relational_exp " << rest_of_maybe_shift_exp_value1.token << "\n";
  Is_Rest_of_maybe_shift_exp( rest_of_maybe_shift_exp_Correct, 
                              rest_of_maybe_shift_exp_Is_Get,
							  rest_of_maybe_shift_exp_value1 );
  if ( rest_of_maybe_shift_exp_Correct == true ) {
  	// cout << "2Rest_of_maybe_relational_exp " << rest_of_maybe_shift_exp_value1.token << "\n";
  	value = rest_of_maybe_shift_exp_value1;
    PeekToken();
    token = m_peek_token;
    correct = true;
    if ( strcmp( token.token.c_str(), "<" ) == 0 || strcmp( token.token.c_str(), ">" ) == 0 ||
         strcmp( token.token.c_str(), ">=" ) == 0 || strcmp( token.token.c_str(), "<=" ) == 0 ) {
      while ( finish == false ) {
        GetToken( token );
        exp = token.token;
        Is_Maybe_shift_exp( maybe_shift_exp_Correct, maybe_shift_exp_Is_Get, maybe_shift_exp_value1 );
        if ( maybe_shift_exp_Correct == false ) {
          correct = false;
          finish = true;
        } // if
      
        else {
          if ( m_IsEOF == true ) {
            correct = true;
            finish = true;
          } // if
          
          else {
          	if ( strcmp( exp.c_str(), "<" ) == 0 ) {
          	  GetValue( rest_of_maybe_shift_exp_value1 );
          	  GetValue( maybe_shift_exp_value1 );
          	  Operator( rest_of_maybe_shift_exp_value1, maybe_shift_exp_value1, exp ) ;
          	  value = rest_of_maybe_shift_exp_value1;
			  
			} // if
			
			else if ( strcmp( exp.c_str(), ">" ) == 0 ) {
			  GetValue( rest_of_maybe_shift_exp_value1 );
          	  GetValue( maybe_shift_exp_value1 );
          	  Operator( rest_of_maybe_shift_exp_value1, maybe_shift_exp_value1, exp ) ;
          	  value = rest_of_maybe_shift_exp_value1;
			  
			} // else if
			
			else if ( strcmp( exp.c_str(), ">=" ) == 0 ) {
			  GetValue( rest_of_maybe_shift_exp_value1 );
          	  GetValue( maybe_shift_exp_value1 );
          	  Operator( rest_of_maybe_shift_exp_value1, maybe_shift_exp_value1, exp ) ;
          	  value = rest_of_maybe_shift_exp_value1;
			  
			} // else if
			
			else if ( strcmp( exp.c_str(), "<=" ) == 0 ) {
			  GetValue( rest_of_maybe_shift_exp_value1 );
          	  GetValue( maybe_shift_exp_value1 );
          	  Operator( rest_of_maybe_shift_exp_value1, maybe_shift_exp_value1, exp ) ;
          	  value = rest_of_maybe_shift_exp_value1;
			  
			} // else if
			
			// cout << "]]]]]]" << value.token << "\n";
			// cout << exp << "\n";
            PeekToken();
            token = m_peek_token;
            if ( strcmp( token.token.c_str(), "<" ) != 0 && strcmp( token.token.c_str(), ">" ) != 0 &&
                 strcmp( token.token.c_str(), ">=" ) != 0 && strcmp( token.token.c_str(), "<=" ) != 0 ) {
              correct = true;
              finish = true;
            } // if
            
          } // else
        
        } // else
      
      } // while
      
    } // if
    
  } // if
  
  else if ( rest_of_maybe_shift_exp_Correct == false && rest_of_maybe_shift_exp_Is_Get == true ) {
    correct = false;
  } // else if
  
  else {
    correct = false;
    Is_Get = false;
  } // else
  
  
  
} // Project::Is_Rest_of_maybe_relational_exp()

// Complete function, 2ok!
void Project::Is_Rest_of_maybe_shift_exp( bool & correct, bool & Is_Get, Token & value ) {
  string exp = "";
  Token token;
  Token rest_of_maybe_additive_exp_value1;
  Token maybe_additive_exp_value1;
  bool finish = false;
  bool rest_of_maybe_additive_exp_Correct = false;
  bool rest_of_maybe_additive_exp_Is_Get = true;
  bool maybe_additive_exp_Correct = false;
  bool maybe_additive_exp_Is_Get = true;
  rest_of_maybe_additive_exp_value1 = value;
  // cout << "1Rest_of_maybe_shift_exp " << rest_of_maybe_additive_exp_value1.token << "\n";
  Is_Rest_of_maybe_additive_exp( rest_of_maybe_additive_exp_Correct, 
                                 rest_of_maybe_additive_exp_Is_Get, 
								 rest_of_maybe_additive_exp_value1 );
  if ( rest_of_maybe_additive_exp_Correct == true ) {
    // cout << "2Rest_of_maybe_shift_exp " << rest_of_maybe_additive_exp_value1.token << "\n";
    value = rest_of_maybe_additive_exp_value1;
    PeekToken();
    token = m_peek_token;
    correct = true;
    // cout << rest_of_maybe_additive_exp_value1.token;
    if ( strcmp( token.token.c_str(), ">>" ) == 0 || strcmp( token.token.c_str(), "<<" ) == 0 ) {
      while ( finish == false ) {
      	if ( strcmp( token.token.c_str(), ">>" ) == 0 && 
		     strcmp( value.token.c_str(), "cin" ) == 0 ) {
      	  m_is_cin = true;
		} // if
		
      	if ( strcmp( token.token.c_str(), "<<" ) == 0 && 
		     strcmp( value.token.c_str(), "cout" ) == 0 ) {
      	  m_is_cout = true;
		} // if
		
      	// value.token = value.token + token.token;
        GetToken( token );
        exp = token.token;
        Is_Maybe_additive_exp( maybe_additive_exp_Correct, 
		                       maybe_additive_exp_Is_Get, 
							   maybe_additive_exp_value1 );
        if ( maybe_additive_exp_Correct == false ) {
          correct = false;
          finish = true;
        } // if
      
        else {
          if ( m_IsEOF == true ) {
            correct = true;
            finish = true;
          } // if
          
          else {
          	value = maybe_additive_exp_value1;
          	if ( strcmp( exp.c_str(), ">>" ) == 0 &&
			     strcmp( rest_of_maybe_additive_exp_value1.token.c_str(), "cin" ) != 0 ) {
      	      GetValue( rest_of_maybe_additive_exp_value1 );
              GetValue( maybe_additive_exp_value1 );  
              Operator( rest_of_maybe_additive_exp_value1, maybe_additive_exp_value1, exp ) ;
              value = rest_of_maybe_additive_exp_value1;
		    } // if
          	
          	else if ( strcmp( exp.c_str(), "<<" ) == 0 &&
			          strcmp( rest_of_maybe_additive_exp_value1.token.c_str(), "cout" ) != 0 ) {
      	      GetValue( rest_of_maybe_additive_exp_value1 );
              GetValue( maybe_additive_exp_value1 );  
              Operator( rest_of_maybe_additive_exp_value1, maybe_additive_exp_value1, exp ) ;
              value = rest_of_maybe_additive_exp_value1;
		    } // else if
          	
          	
          	if ( m_is_cin == true ) {
          	  m_cin_token.push_back( maybe_additive_exp_value1 );
			} // if
			
			if ( m_is_cout == true &&
			     strcmp( rest_of_maybe_additive_exp_value1.token.c_str(), "cout" ) == 0 ) {
			  // cout << maybe_additive_exp_value1.token;
			  if ( strcmp( value.type.c_str(), "IDE" ) == 0 )
			    GetValue( value );
			  if ( Allow_before_m_shouldnot_operator_list2() == true )
			    m_cout_token.push_back( value );
			} // if
			
          	// value.token = value.token + maybe_additive_exp_value1.token;
            PeekToken();
            token = m_peek_token;
            if ( strcmp( token.token.c_str(), ">>" ) != 0 && strcmp( token.token.c_str(), "<<" ) != 0 ) {
              correct = true;
              finish = true; 
            } // if
            
          } // else
        
        } // else
      
      
      } // while
      
    } // if
    
    
  } // if
  
  else if ( rest_of_maybe_additive_exp_Correct == false && rest_of_maybe_additive_exp_Is_Get == true ) {
    correct = false;
  } // else if
  
  else {
    correct = false;
    Is_Get = false;
  } // else
  
  
  
} // Project::Is_Rest_of_maybe_shift_exp()

// Complete function, 2ok!
void Project::Is_Maybe_additive_exp( bool & correct, bool & Is_Get, Token & value ) {
  Token token;
  string exp = "";
  bool finish = false;
  bool maybe_mult_exp_Correct = false;
  bool maybe_mult_exp_Is_Get = true;
  Token maybe_mult_exp_value1, maybe_mult_exp_value2;
  Is_Maybe_mult_exp( maybe_mult_exp_Correct, maybe_mult_exp_Is_Get, maybe_mult_exp_value1 );
  if ( maybe_mult_exp_Correct == true ) {
    PeekToken();
    token = m_peek_token;
    correct = true;
    value = maybe_mult_exp_value1;
    if ( strcmp( token.token.c_str(), "+" ) == 0 || strcmp( token.token.c_str(), "-" ) == 0 ) {
      while ( finish == false ) {
        GetToken( token );
        exp = token.token;
        Is_Maybe_mult_exp( maybe_mult_exp_Correct, maybe_mult_exp_Is_Get, maybe_mult_exp_value2 );
        if ( maybe_mult_exp_Correct == false ) {
          correct = false;
          finish = true;
        } // if
      
        else {
          if ( m_IsEOF == true ) {
            correct = true;
            finish = true;
          } // if
          
          else {
          	if ( strcmp( exp.c_str(), "+" ) == 0 ) {
          	  GetValue( maybe_mult_exp_value1 );
          	  GetValue( maybe_mult_exp_value2 ); 
          	  Operator( maybe_mult_exp_value1, maybe_mult_exp_value2, exp ) ;
              value = maybe_mult_exp_value1;
			} // if
			
			else if ( strcmp( exp.c_str(), "-" ) == 0 ) {
			  GetValue( maybe_mult_exp_value1 );
          	  GetValue( maybe_mult_exp_value2 ); 
          	  Operator( maybe_mult_exp_value1, maybe_mult_exp_value2, exp ) ;
              value = maybe_mult_exp_value1;
			} // else if
			
            PeekToken();
            token = m_peek_token;
			
            if ( strcmp( token.token.c_str(), "+" ) != 0 && strcmp( token.token.c_str(), "-" ) != 0 ) {
              correct = true;
              finish = true;
            } // if
            
          } // else
        
        } // else
      
      
      } // while
      
    } // if
    
  } // if
  
  else if ( maybe_mult_exp_Correct == false && maybe_mult_exp_Is_Get == true ) {
    correct = false;
  } // else if
  
  else {
    correct = false;
    Is_Get = false;
  } // else 
  
  if ( correct == true ) {
  	value = maybe_mult_exp_value1;
  } // if
  
  
} // Project::Is_Maybe_additive_exp()

// Complete function, 2ok!
void Project::Is_Rest_of_maybe_additive_exp( bool & correct, bool & Is_Get, Token & value ) {
  Token token;
  string exp = "";
  bool finish = false;
  bool rest_of_maybe_mult_exp_Correct = false;
  bool rest_of_maybe_mult_exp_Is_Get = true;
  bool maybe_mult_exp_Correct = false;
  bool maybe_mult_exp_Is_Get = true;
  Token rest_of_maybe_mult_exp_value1, maybe_mult_exp_value1;
  rest_of_maybe_mult_exp_value1 = value;
  Is_Rest_of_maybe_mult_exp( rest_of_maybe_mult_exp_Correct, 
                             rest_of_maybe_mult_exp_Is_Get, 
							 rest_of_maybe_mult_exp_value1 );
  if ( rest_of_maybe_mult_exp_Correct == true ) {
    PeekToken();
    token = m_peek_token;
    correct = true;
    value.token = rest_of_maybe_mult_exp_value1.token;
    if ( strcmp( token.token.c_str(), "+" ) == 0 || 
         strcmp( token.token.c_str(), "-" ) == 0 ) {
      while ( finish == false ) {
      	exp = token.token;
        GetToken( token );
        Is_Maybe_mult_exp( maybe_mult_exp_Correct, maybe_mult_exp_Is_Get, maybe_mult_exp_value1 );
        if ( maybe_mult_exp_Correct == false ) {
          correct = false;
          finish = true;    
        } // if
      
        else {
          if ( m_IsEOF == true ) {
            correct = true;
            finish = true;
          } // if
          
          else {
          	GetValue( rest_of_maybe_mult_exp_value1 );
			GetValue( maybe_mult_exp_value1 );
          	if ( strcmp( exp.c_str(), "+" ) == 0 ) {
          	  Operator( rest_of_maybe_mult_exp_value1, maybe_mult_exp_value1, exp ) ;
          	  value = rest_of_maybe_mult_exp_value1;
          	  // cout << rest_of_maybe_mult_exp_value1.token << "\n";
			} // if
			
			else if ( strcmp( exp.c_str(), "-" ) == 0 ) {
          	  Operator( rest_of_maybe_mult_exp_value1, maybe_mult_exp_value1, exp ) ;
          	  value = rest_of_maybe_mult_exp_value1;
			} // if
			
            PeekToken();
            token = m_peek_token;
            // cout << maybe_mult_exp_value1.token << "\n";
            if ( strcmp( token.token.c_str(), "+" ) != 0 && 
                 strcmp( token.token.c_str(), "-" ) != 0 ) {
              correct = true;
              finish = true;
            } // if
            
          } // else
        
        } // else
      
      } // while
      
    } // if
    
  } // if
  
  else if ( rest_of_maybe_mult_exp_Correct == false && rest_of_maybe_mult_exp_Is_Get == true ) {
    correct = false;
  } // else if
  
  else {
    correct = false;
    Is_Get = false;
  } // else 
  

  
  
} // Project::Is_Rest_of_maybe_additive_exp()

// Complete function, 2ok!
void Project::Is_Maybe_mult_exp( bool & correct, bool & Is_Get, Token & value ) {
  Token unary_exp_value1, rest_of_maybe_mult_exp_value1;
  bool unary_exp_Correct = false;
  bool unary_exp_Is_Get = true;
  bool rest_of_maybe_mult_exp_Correct = false;
  bool rest_of_maybe_mult_exp_Is_Get = true;
  Is_Unary_exp( unary_exp_Correct, unary_exp_Is_Get, unary_exp_value1 );
  if ( unary_exp_Correct == true ) {
  	value = unary_exp_value1;
  	rest_of_maybe_mult_exp_value1 = value;
    Is_Rest_of_maybe_mult_exp( rest_of_maybe_mult_exp_Correct, 
	                           rest_of_maybe_mult_exp_Is_Get, 
							   rest_of_maybe_mult_exp_value1 );
    if ( rest_of_maybe_mult_exp_Correct == true ) {
      value = rest_of_maybe_mult_exp_value1;
      correct = true;
    } // if
    
    else correct = false;
    
  } // if
  
  else if ( unary_exp_Correct == false && unary_exp_Is_Get == true ) {
    correct = false;
  } // else if
  
  else {
    correct = false;
    Is_Get = false;
  } // else
  
  
} // Project::Is_Maybe_mult_exp()

// Complete function, 2ok!
void Project::Is_Rest_of_maybe_mult_exp( bool & correct, bool & Is_Get, Token & value ) {
  Token token;
  Token unary_exp_value1;
  double num;
  bool finish = false;
  bool unary_exp_Correct = false;
  bool unary_exp_Is_Get = true;
  string exp = "";
  PeekToken();
  token = m_peek_token;
  correct = true;
  if ( strcmp( token.token.c_str(), "*" ) == 0 || 
       strcmp( token.token.c_str(), "/" ) == 0 || 
       strcmp( token.token.c_str(), "%" ) == 0 ) {
    while ( finish == false ) {
      GetToken( token );
      exp = token.token;
      Is_Unary_exp( unary_exp_Correct, unary_exp_Is_Get, unary_exp_value1 );
      if ( unary_exp_Correct == false ) {
        correct = false;
        finish = true;    
      } // if
    
      else {
        if ( m_IsEOF == true ) {
          correct = true;
          finish = true;
        } // if
        
        else {
          if ( strcmp( value.type.c_str(), "IDE" ) == 0 )
            GetValue( value );
          if ( strcmp( unary_exp_value1.type.c_str(), "IDE" ) == 0 )
            GetValue( unary_exp_value1 );
		  if ( strcmp( exp.c_str(), "*" ) == 0 ) {
		  	Operator( value, unary_exp_value1, exp ) ;
		  } // if
		  
		  else if ( strcmp( exp.c_str(), "/" ) == 0 ) {
		  	Operator( value, unary_exp_value1, exp ) ;
		  } // else if
		  
		  else if ( strcmp( exp.c_str(), "%" ) == 0 ) {
		  	Operator( value, unary_exp_value1, exp ) ;
		  } // else if
		  
          PeekToken();
          token = m_peek_token;
          if ( strcmp( token.token.c_str(), "*" ) != 0 && 
               strcmp( token.token.c_str(), "/" ) != 0 && 
               strcmp( token.token.c_str(), "%" ) != 0 ) {
            correct = true;
            finish = true;                  
          } // if
          
        } // else
      
      } // else
    
    } // while
    
  } // if
  
  else Is_Get = false;
  
  
} // Project::Is_Rest_of_maybe_mult_exp()

// Complete function, 2ok!
void Project::Is_Unary_exp( bool & correct, bool & Is_Get, Token & value ) {
  Token token;
  int sign_value;
  Token sigh_value1 ;
  Token sigh_value2 ;
  Token expression_value1;
  Token signed_unary_exp_value1;
  Token unsigned_unary_exp_value1;
  bool sign_Correct = false;
  bool sign_Is_Get = true;
  bool signed_unary_exp_Correct = false;
  bool signed_unary_exp_Is_Get = true;
  bool expression_Correct = false;
  bool expression_Is_Get = true;
  bool unsigned_unary_exp_Correct = false;
  bool unsigned_unary_exp_Is_Get = true;
  bool is_PP = false;
  bool is_MM = false;
  sigh_value1.token = "";
  Is_Sign( sign_Correct, sign_Is_Get, sigh_value1 );
  if ( sign_Correct == true ) {
    Is_Sign( sign_Correct, sign_Is_Get, sigh_value1 );
    while ( sign_Correct == true ) {
      Is_Sign( sign_Correct, sign_Is_Get, sigh_value1 );
    } // while
    
    Is_Signed_unary_exp( signed_unary_exp_Correct, 
	                     signed_unary_exp_Is_Get, 
						 signed_unary_exp_value1,
						 sigh_value1 );
    if ( signed_unary_exp_Correct == true ) {
      correct = true;
      value = signed_unary_exp_value1;
    } // if
    
    else correct = false;
    
  } // if
  
  else {
    if ( sign_Correct == false && sign_Is_Get == true ) {
      correct = false;
    } // if
    
    else {
      PeekToken();
      token = m_peek_token;
      if ( strcmp( token.token.c_str(), "++" ) == 0 || strcmp( token.token.c_str(), "--" ) == 0 ) {
      	if ( strcmp( token.token.c_str(), "++" ) == 0 ) {
      	  is_PP = true;
		} // if
		
		else if ( strcmp( token.token.c_str(), "--" ) == 0 ) {
		  is_MM = true;
		} // else if
		
        GetToken( token );
        PeekToken();
        token = m_peek_token;
        if ( strcmp( token.type.c_str(), "IDE" ) == 0 ) {
          GetToken( token );
          
          
          value = token;
          correct = true;
          PeekToken();
          token = m_peek_token;
          if ( strcmp( token.token.c_str(), "[" ) == 0 ) {
            GetToken( token );
            Is_Expression( expression_Correct, expression_Is_Get, expression_value1 );
            if ( expression_Correct == true ) {
              value.select_arrary_num = expression_value1.token;
              if ( is_PP == true ) {
          	    Do_First_PP( value );
          	    is_PP = false;
		      } // if
		  
		      else if ( is_MM == true ) {
          	    Do_First_MM( value );
          	    is_MM = false;
		      } // else if
              
              
              PeekToken();
              token = m_peek_token;
              if ( strcmp( token.token.c_str(), "]" ) == 0 ) {
                GetToken( token );
                correct = true;
              } // if
          
              else correct = false;
          
            } // if
        
            else correct = false;
        
          } // if
        
          else {
          	if ( is_PP == true ) {
          	  Do_First_PP( value );
          	  is_PP = false;
		    } // if
		  
		    else if ( is_MM == true ) {
          	  Do_First_MM( value );
          	  is_MM = false;
		    } // else if
		    
		  } // else
		   
        } // if
      
      } // if
    
      else {
        Is_Unsigned_unary_exp( unsigned_unary_exp_Correct, 
		                       unsigned_unary_exp_Is_Get, 
							   unsigned_unary_exp_value1 ) ;
        if ( unsigned_unary_exp_Correct == true ) {
          value = unsigned_unary_exp_value1;
          correct = true;   
        } // if
      
        else if ( unsigned_unary_exp_Correct == false && unsigned_unary_exp_Is_Get == true ) {
          correct = false;
        } // else if
        
        else {
          correct = false;
          Is_Get = false;
        } // else
      
      } // else
      
    } // else
        
  } // else  
  
} // Project::Is_Unary_exp()


// Complete function, 2ok!
void Project::Is_Unsigned_unary_exp( bool & correct, bool & Is_Get, Token & value ) {
  Token token;
  Token expression_value1;
  bool ide_exist = false;
  bool parameter_exist = false;
  bool function_exist = false;
  bool localData_exist = false;
  bool functData_exist = false;
  bool actual_parameter_list_Correct = false;
  bool actual_parameter_list_Is_Get = true;
  bool expression_Correct = false;
  bool expression_Is_Get = true;
  PeekToken();
  token = m_peek_token;
  if ( strcmp( token.type.c_str(), "IDE" ) == 0 ) {
    if ( m_now_definition == false ) {
      for ( int i = 0; i < m_fuction_table.size() ; i++ ) {
        if ( strcmp( token.token.c_str(), m_fuction_table[i].token.c_str() ) == 0  ) {
          function_exist = true;
        } // if
      
      } // for
        
      for ( int i = 0; i < m_define_table.size() ; i++ ) {
        if ( strcmp( token.token.c_str(), m_define_table[i].token_name.token.c_str() ) == 0  ) {
          ide_exist = true;
        } // if
      
      } // for
        
    } // if
    
    else if ( m_now_definition == true && m_function == false ) {
      for ( int i = 0; i < m_fuction_table.size() ; i++ ) {
        if ( strcmp( token.token.c_str(), m_fuction_table[i].token.c_str() ) == 0  ) {
          function_exist = true;
        } // if
      
      } // for
       
      
      for ( int i = 0; i < m_define_table.size() ; i++ ) {
        if ( strcmp( token.token.c_str(), m_define_table[i].token_name.token.c_str() ) == 0  ) {
          ide_exist = true;
        } // if
      
      } // for
      
      for ( int i = 0; i < m_localData_table.size() ; i++ ) {
        if ( strcmp( token.token.c_str(), m_localData_table[i].token_name.token.c_str() ) == 0  ) {
          localData_exist = true;
        } // if
      
      } // for
      
      
	} // else if
    
    else {
      for ( int i = 0; i < m_fuction_table.size() ; i++ ) {
        if ( strcmp( token.token.c_str(), m_fuction_table[i].token.c_str() ) == 0  ) {
          function_exist = true;
        } // if
      
      } // for
       
      
      for ( int i = 0; i < m_define_table.size() ; i++ ) {
        if ( strcmp( token.token.c_str(), m_define_table[i].token_name.token.c_str() ) == 0  ) {
          ide_exist = true;
        } // if
      
      } // for
      
      for ( int i = 0; i < m_fuction_table[m_fuction_table.size()-1].data.size() ; i++ ) {
        if ( strcmp( token.token.c_str(), 
                     m_fuction_table[m_fuction_table.size()-1].data[i].token.c_str() ) == 0  
           ) {
          functData_exist = true;
        } // if
      
      } // for
      
      
    } // else
    

    
    if ( ide_exist == false && function_exist == false && functData_exist == false && 
	     localData_exist == false ) {
      m_undefined_ide = true;
      correct = false;
    } // if
    
    
    else {
      GetToken( token );
      token.type = "IDE";
      m_PP_token = token;
      m_MM_token = token;
      value = token;
      PeekToken();
      token = m_peek_token;
      correct = true;
      if ( strcmp( token.token.c_str(), "(" ) == 0 ||
           strcmp( token.token.c_str(), "[" ) == 0 ) {
        if ( strcmp( token.token.c_str(), "(" ) == 0 ) {
          GetToken( token );
          Is_Actual_parameter_list( actual_parameter_list_Correct, actual_parameter_list_Is_Get );
          if ( actual_parameter_list_Correct == false && actual_parameter_list_Is_Get == true ) {
            correct = false;    
          } // if
          
          else {
            PeekToken();
            token = m_peek_token;
            if ( strcmp( token.token.c_str(), ")" ) == 0 ) {
              GetToken( token );
              correct = true;
            } // if
        
            else correct = false;
            
          } // else
          
        
        } // if
      
        else if ( strcmp( token.token.c_str(), "[" ) == 0 ) {
          GetToken( token );
          Is_Expression( expression_Correct, expression_Is_Get, expression_value1 );
          if ( expression_Correct == true ) {
          	value.select_arrary_num = expression_value1.token;
          	m_PP_token.select_arrary_num = expression_value1.token;
          	m_MM_token.select_arrary_num = expression_value1.token;
            PeekToken();
            token = m_peek_token;
            if ( strcmp( token.token.c_str(), "]" ) == 0 ) {
              GetToken( token );
              correct = true;
              PeekToken();
              token = m_peek_token;
              if ( strcmp( token.token.c_str(), "++" ) == 0 || strcmp( token.token.c_str(), "--" ) == 0 ) {
                GetToken( token );
                GetValue( value );
                SetType( value );
                /*
                PeekToken();
                // token = m_peek_token;
                if ( strcmp( token.token.c_str(), "++" ) == 0 && 
				     strcmp( m_peek_token.token.c_str(), ";" ) != 0 ) {
				  Do_First_PP( value );	
				} // if
				
				else if ( strcmp( token.token.c_str(), "--" ) == 0 &&
				          strcmp( m_peek_token.token.c_str(), ";" ) != 0 ) {
                  Do_First_MM( value );
				} // else if
				
				
				else if ( strcmp( token.token.c_str(), "++" ) == 0 &&
				          strcmp( m_peek_token.token.c_str(), ";" ) == 0 ) {
				  Do_Last_PP( m_PP_token );
				} // else if
                  
                // m_PP_table.push_back( m_PP_token ) ;
                else if ( strcmp( token.token.c_str(), "--" ) == 0 &&
				          strcmp( m_peek_token.token.c_str(), ";" ) == 0 ) {
                  Do_Last_MM( m_MM_token );
				} // else if
                */
                if ( strcmp( token.token.c_str(), "++" ) == 0 )
                  Do_Last_PP( m_PP_token );
                  
                else if ( strcmp( token.token.c_str(), "--" ) == 0 )  
                  Do_Last_MM( m_MM_token );
                  // m_MM_table.push_back( m_MM_token ) ;
              } // if
            
            } // if
          
            else correct = false;
          
          } // if
        
          else correct = false;
        
        } // else if
        
        else {
          if ( strcmp( token.token.c_str(), "++" ) == 0 || strcmp( token.token.c_str(), "--" ) == 0 ) {
            GetToken( token );
            GetValue( value );
            SetType( value );
            /*
            PeekToken();
            if ( strcmp( token.token.c_str(), "++" ) == 0 && 
				 strcmp( m_peek_token.token.c_str(), ";" ) != 0 ) {
			  Do_First_PP( value );	
			} // if
				
			else if ( strcmp( token.token.c_str(), "--" ) == 0 &&
				      strcmp( m_peek_token.token.c_str(), ";" ) != 0 ) {
              Do_First_MM( value );
			} // else if
				
				
			else if ( strcmp( token.token.c_str(), "++" ) == 0 &&
				      strcmp( m_peek_token.token.c_str(), ";" ) == 0 ) {
			  Do_Last_PP( m_PP_token );
			} // else if
                  
            // m_PP_table.push_back( m_PP_token ) ;
            else if ( strcmp( token.token.c_str(), "--" ) == 0 &&
				      strcmp( m_peek_token.token.c_str(), ";" ) == 0 ) {
              Do_Last_MM( m_MM_token );
			} // else if
			*/
            if ( strcmp( token.token.c_str(), "++" ) == 0 )
              Do_Last_PP( m_PP_token );
            else if ( strcmp( token.token.c_str(), "--" ) == 0 )  
              Do_Last_MM( m_MM_token );
            
          } // if
          
		} // else
        
      } // if   
      
      else {
        if ( strcmp( token.token.c_str(), "++" ) == 0 || strcmp( token.token.c_str(), "--" ) == 0 ) {
          GetToken( token );
          GetValue( value );
          SetType( value );
          /*
          PeekToken();
          if ( strcmp( token.token.c_str(), "++" ) == 0 && 
			   strcmp( m_peek_token.token.c_str(), ";" ) != 0 ) {
		    Do_First_PP( value );	
		  } // if
				
		  else if ( strcmp( token.token.c_str(), "--" ) == 0 &&
				    strcmp( m_peek_token.token.c_str(), ";" ) != 0 ) {
            Do_First_MM( value );
		  } // else if
				
				
		  else if ( strcmp( token.token.c_str(), "++" ) == 0 &&
				    strcmp( m_peek_token.token.c_str(), ";" ) == 0 ) {
			Do_Last_PP( m_PP_token );
		  } // else if
                  
          // m_PP_table.push_back( m_PP_token ) ;
          else if ( strcmp( token.token.c_str(), "--" ) == 0 &&
				    strcmp( m_peek_token.token.c_str(), ";" ) == 0 ) {
            Do_Last_MM( m_MM_token );
		  } // else if
          */
          
          if ( strcmp( token.token.c_str(), "++" ) == 0 )
            Do_Last_PP( m_PP_token );
          else if ( strcmp( token.token.c_str(), "--" ) == 0 )  
            Do_Last_MM( m_MM_token );
          
        } // if
          
	  } // else
      
        
    } // else
    
    
  } // if
  
  else if ( strcmp( token.type.c_str(), "CONSTANT" ) == 0 ) {
    GetToken( token );
    SetType( token );
    value = token;
    correct = true;
  } // else if
  
  else if ( strcmp( token.token.c_str(), "(" ) == 0 ) {
    GetToken( token );
    Is_Expression( expression_Correct, expression_Is_Get, expression_value1 );
    if ( expression_Correct == true ) {
      value = expression_value1;
      PeekToken();
      token = m_peek_token;
      if ( strcmp( token.token.c_str(), ")" ) == 0 ) {
        GetToken( token );
        correct = true;
      } // if
      
      else correct = false;
      
    } // if
    
    else correct = false;
    
  } // else if
  
  else {
    correct = false;
    Is_Get = false;
  } // else
  
  
} // Project::Is_Unsigned_unary_exp()






int main() {
  string m_input_str = "";
  string str = "";
  char ch ;
  cin >> ch;
  ch = cin.get();
  u_ch = ch;
  char temp_m_input_str[100];
  cout << "Our-C running ...\n";
  Project project;
  // cout << "kevin\n";
  
} // main()

