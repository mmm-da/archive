#if !defined(__FORM7_H)
   #define __FORM7_H
     //const ...; // ����������� �������������� ��������
     typedef struct _str
                 {
                    char *s; /* ��������� �� ������. ������ ��� ����� ������ s �������� ������������ ����� ������ */
                    unsigned max; /* ������������ ���������� �������� � ������, �������������� ��� ������������� */
                  }str;
     typedef str *string1;
       string1 InitStr(unsigned n);
       void WriteToStr(char *oS, string1 st);
       void InputStr(string1 st);
       void OutputStr(string1 st);
       int Comp(string1 s1, string1 s2);
       void Delete(string1 s, unsigned Index, unsigned Count);
       void Insert(string1 Subs, string1 s, unsigned Index);
       void Concat(string1 s1, string1 s2, string1 srez);
       void Copy(string1 s, unsigned Index, unsigned Count,string1 Subs);
       unsigned short Length(string1 s);
       unsigned Pos(string1 SubS, string1 s);
       void DoneStr(string1 st);
       int StrError;
       void setLenght(unsigned short size,string1 st);
   #endif
