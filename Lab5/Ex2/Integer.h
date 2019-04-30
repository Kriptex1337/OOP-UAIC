class Integer
{
    int Element;
public:
    Integer();
    Integer(int);
    Integer(const Integer&);
    int GetElement();
    bool operator<(const Integer&);
};
