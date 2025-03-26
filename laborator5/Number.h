class Number
{
   // add data members
   char *val;
   int base;
   int nr;
public:
   Number(const char * value, int base); // where base is between 2 and 16
   Number(int val);
   Number(const Number &other);
   Number(Number && d);
   ~Number();

   // add operators and copy/move constructor
   bool operator >(const Number & other);
   bool operator >=(const Number & other);
   bool operator <(const Number & other);
   bool operator <=(const Number & other);
   bool operator ==(const Number & other);
   bool operator --();
   bool operator --(int val);
   char operator [](int index);
   friend Number operator +(Number a,Number b);
   friend Number operator -(Number a,Number b);
   Number &operator =(const Number &other);
   Number &operator =(int val);
   Number &operator =(char *x);
   Number &operator +=(Number & other);
   void SwitchBase(int newBase);
   void Print();
   int  GetDigitsCount(); // returns the number of digits for the current number
   int  GetBase(); // returns the current base
};

