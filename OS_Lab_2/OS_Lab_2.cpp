#include <iostream>

using namespace std;

class Row
{
    string rowValue;
public:
    Row(string rowValue_)
    {
        rowValue = rowValue_;
    }
    int LengthCalculation()
    {
        int size = rowValue.size();

        return size;
    }
};
class SymbolicRow : Row
{

};


int main()
{
    Row row("12345678hyhhrev");
    cout << row.LengthCalculation();
}