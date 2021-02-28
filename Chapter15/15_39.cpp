#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

#include "Textquery.h"
#include "Query.h"

int main()
{
  ifstream ifs("text.txt");
  TextQuery tq(ifs);
  Query q = Query("fiery") & Query("bird") | Query("wind");
  cout<<q<<endl;
  return 0;
}