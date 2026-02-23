#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstdlib> 
#include <stack>

using namespace std;

class Fraction
{
    friend Fraction operator+(const Fraction& frac1, const Fraction& frac2); //重载+运算符
    friend Fraction operator-(const Fraction& frac1, const Fraction& frac2); //重载-运算符
    friend Fraction operator*(const Fraction& frac1, const Fraction& frac2); //重载*运算符
    friend Fraction operator/(const Fraction& frac1, const Fraction& frac2); //重载/运算符
	friend bool operator==(Fraction frac1, Fraction frac2);                  //重载==运算符
    friend bool operator>(const Fraction& frac1, const Fraction& frac2);     //重载>运算符
    friend bool operator<(const Fraction& frac1, const Fraction& frac2);     //重载<运算符
    friend ostream& operator<<(ostream& out, const Fraction& frac);          //重载<<运算符
    friend istream& operator>>(istream& in, Fraction& frac);                 //重载>>运算符
    friend void sortFraction(vector<Fraction>& fractions,string m);//对分数数组排序
public:
    Fraction();                              //无参造函数
    Fraction(int n, int d);                  //带参造函数
    Fraction(const Fraction& f);             //复制造函数
    void setFraction(int n, int d);          //设置分数的分子和分母
    int getNumer();                          //获取分数的分子
    int getDeno();                           //获取分数的分母
    void RdcFrc();                           //当前分数约分
	Fraction& operator=(const Fraction& that);//重载=运算符 
private:
    int numer; //分子
    int deno;  //分母    
};


Fraction& Fraction::operator=(const Fraction& that){
	if(this!=&that){
		this->deno=that.deno;
		this->numer=that.numer;
	}
	return *this;
}

Fraction operator+(const Fraction& frac1, const Fraction& frac2){
	int newnumer=frac1.numer*frac2.deno+frac2.numer*frac1.deno;
	int newdeno=frac1.deno*frac2.deno;
	return Fraction(newnumer,newdeno);
}

Fraction operator-(const Fraction& frac1, const Fraction& frac2){
	int newnumer=frac1.numer*frac2.deno-frac2.numer*frac1.deno;
	int newdeno=frac1.deno*frac2.deno;
	return Fraction(newnumer,newdeno);
}

Fraction operator*(const Fraction& frac1, const Fraction& frac2){
	int newnumer=frac1.numer*frac2.numer;
	int newdeno=frac1.deno*frac2.deno;
	return Fraction(newnumer,newdeno);
}

Fraction operator/(const Fraction& frac1, const Fraction& frac2){
	int newnumer=frac1.numer*frac2.deno;
	int newdeno=frac2.numer*frac1.deno;
	return Fraction(newnumer,newdeno);
}

bool operator==(Fraction frac1, Fraction frac2){
	double a=(double)frac1.numer/(double)frac1.deno;
	double b=(double)frac2.numer/(double)frac2.deno;
	if(a==b){
		return true;
	}else{
		return false;
	}
}

bool operator>(const Fraction& frac1,const Fraction& frac2){
	double a=(double)frac1.numer/(double)frac1.deno;
	double b=(double)frac2.numer/(double)frac2.deno;
	if(a>b){
		return true;
	}else{
		return false;
	}
}

bool operator<(const Fraction& frac1,const Fraction& frac2){
	double a=(double)frac1.numer/(double)frac1.deno;
	double b=(double)frac2.numer/(double)frac2.deno;
	if(a<b){
		return true;
	}else{
		return false;
	}
}

ostream& operator<<(ostream& out, const Fraction& frac){
	out<<frac.numer<<"/"<<frac.deno;
	return out;
}

istream& operator>>(istream& in, Fraction& frac){
	char m;
	in>>frac.numer>>m>>frac.deno;
	return in;
}

void sortFraction(vector<Fraction>& fractions,string m){
	if(m=="<"){
		sort(fractions.begin(),fractions.end(), [](const Fraction& a,const Fraction& b){
			return a<b;
		});
	}
	if(m==">"){
		sort(fractions.begin(),fractions.end(), [](const Fraction& a,const Fraction& b){
			return a>b;
		});
	}
}

Fraction::Fraction() : numer(0),deno(1){}

Fraction::Fraction(int n, int d) : numer(n),deno(d){
	RdcFrc();
}

Fraction::Fraction(const Fraction& f) : numer(f.numer),deno(f.deno){}

void Fraction::setFraction(int n, int d){
	numer=n;
	deno=d;
}

int Fraction::getNumer(){
	return numer;
}

int Fraction::getDeno(){
	return deno;
}

void Fraction::RdcFrc(){
	if(deno<0){
		numer=-numer;
		deno=-deno;
	}
	int d=deno;
	int n=abs(numer);
	while(d!=0){
		int temp=d;
		d=n%d;
		n=temp;
	}
	numer=numer/n;
	deno=deno/n;
}

void bian(int m){
	if(m==0){
		m++;
	}else{
		m--;
	}
}

bool weihe(char m){
	if(m=='1'){
		return false;
	}
	if(m=='0'){
		return false;
	}
	if(m=='2'){
		return false;
	}
	if(m=='3'){
		return false;
	}
	if(m=='4'){
		return false;
	}
	if(m=='5'){
		return false;
	}
	if(m=='6'){
		return false;
	}
	if(m=='7'){
		return false;
	}
	if(m=='8'){
		return false;
	}
	if(m=='9'){
		return false;
	}
	if(m=='+'){
		return false;
	}
	if(m=='-'){
		return false;
	}
	if(m=='*'){
		return false;
	}
	if(m=='/'){
		return false;
	}
	if(m=='('){
		return false;
	}
	if(m=='$'){
		return false;
	}
	if(m==')'){
		return false;
	}
	if(m=='['){
		return false;
	}
	if(m==']'){
		return false;
	}
	if(m=='{'){
		return false;
	}
	if(m=='}'){
		return false;
	}
	return true;
}

string fra_to_string(const Fraction& fra){
	stringstream ss;
	ss<<fra;
	return ss.str();
}

Fraction str_to_fra(string str){
	int m=str.size();
	for(int i=0;i<m;i++){
		if(str[i]=='/'){
			if(str[i+1]=='/'){
				return Fraction(0,0);
			}
		}
	}
	if(str[0]=='/'||str[m-1]=='/'){
		return Fraction(0,0);
	}
	
	string s1="/";
	str=str+s1;
	int deno;
	int numer;
	
	int k=-2;
	int ahead=0;
	for(int i=0;i<=m;i++){
		if(str[i]=='/'){
			if(k==0){
				string sn(str,ahead,i-ahead);
				int n=stoi(sn);
				numer=numer*n;
				ahead=i+1;
				k++;
				continue;
			}
			if(k==1){
				string sd(str,ahead,i-ahead);
				int d=stoi(sd);
				deno=deno*d;
				k--;
				ahead=i+1;
				continue;
			}
			if(k==-2){
				string snumer(str,ahead,i-ahead);
				numer=stoi(snumer);
				ahead=i+1;
				k++;
				continue;
			}
			if(k==-1){
				string sdeno(str,ahead,i-ahead);
				deno=stoi(sdeno);
				ahead=i+1;
				k++;
				continue;
			}
		}
		
	}
	
	Fraction Fra(numer,deno);
	Fra.RdcFrc();
	return Fra;
} 

bool first_count(string r){
	int n=r.size();
	for(int i=0;i<n;i++){
		if(weihe(r[i])){
			return false;
		}
	}
	return true;
} 
//初步排查 

template<typename T>//判断是数字还是运算符 
bool number(T a){
	if((int)a>=0&&(int)a<=9) return true;
	else return false;
}

bool right(string s){
	int m=s.length();
	for(int i=0;i<m;i++){
		if((!number(s[i]))&&(!(s[i]=='/'))&&(!(s[i]==','))){
			if(s[i]=='>'||s[i]=='<'){
				if(i==m-1){
					return true;
				}else{
					return false;
				}
			}else{return true;}
		}
	}
	return true;
}

Fraction basic_count(string s) {
    // 先处理所有乘法
    while (true) {
        bool has_mul = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '*') {
                has_mul = true;
                // 找到乘号左边的分数
                int left_start = i - 1;
                while (left_start >= 0 && s[left_start] != '+' && s[left_start] != '-') {
                    left_start--;
                }
                left_start++;
                
                // 找到乘号右边的分数
                int right_end = i + 1;
                while (right_end < s.length() && s[right_end] != '+' && s[right_end] != '-' && s[right_end] != '*') {
                    right_end++;
                }
                
                string left_str = s.substr(left_start, i - left_start);
                string right_str = s.substr(i + 1, right_end - i - 1);
                
                Fraction left_fra = str_to_fra(left_str);
                Fraction right_fra = str_to_fra(right_str);
                Fraction result = left_fra * right_fra;
                
                // 替换表达式中的乘法部分
                string result_str = fra_to_string(result);
                s = s.substr(0, left_start) + result_str + s.substr(right_end);
                break; // 重新开始循环，因为字符串改变了
            }
        }
        if (!has_mul) break;
    }
    
    // 处理加减法
    vector<Fraction> fractions;
    vector<char> operators;
    
    // 解析表达式
    int start = 0;
    if (s[0] == '+' || s[0] == '-') {
        return Fraction(0,0);
    }
    
    for (int i = start; i <= s.length(); i++) {
        if (i == s.length() || s[i] == '+' || s[i] == '-') {
            string fra_str = s.substr(start, i - start);
            if (!fra_str.empty()) {
                fractions.push_back(str_to_fra(fra_str));
            }else{
				return Fraction(0,0);
			}
            if (i < s.length()) {
                operators.push_back(s[i]);
            }
            start = i + 1;
        }
    }
    
    // 计算加减法
    Fraction result = fractions[0];
    for (int i = 0; i < operators.size(); i++) {
        if (operators[i] == '+') {
            result = result + fractions[i + 1];
        } else { // '-'
            result = result - fractions[i + 1];
        }
    }
    
    return result;
}
//无括号 

Fraction NB_count(string s) {
    // 处理括号，从内到外
    stack<int> stk;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stk.push(i);
        } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (stk.empty()) {
                return Fraction(0, 0); // 括号不匹配
            }
            
            int start = stk.top();
            stk.pop();
            
            // 检查括号是否匹配
            char open_bracket = s[start];
            char close_bracket = s[i];
            bool matched = false;
            if (open_bracket == '(' && close_bracket == ')') matched = true;
            if (open_bracket == '[' && close_bracket == ']') matched = true;
            if (open_bracket == '{' && close_bracket == '}') matched = true;
            
            if (!matched) {
                return Fraction(0, 0); // 括号类型不匹配
            }
            
            // 提取括号内的表达式并计算
            string inner_expr = s.substr(start + 1, i - start - 1);
            Fraction inner_result = basic_count(inner_expr);
            
            // 替换括号部分
            string result_str = fra_to_string(inner_result);
            s = s.substr(0, start) + result_str + s.substr(i + 1);
            
            // 重置索引，因为字符串改变了
            i = start + result_str.length() - 1;
        }
    }
    
    if (!stk.empty()) {
        return Fraction(0, 0); // 有未闭合的括号
    }
    
    // 处理完所有括号后，计算最终结果
    return basic_count(s);
}
//带括号 

void clean(){
	system("pause");
	system("cls");
} 

int main(){
	while(true){
		cout<<"请选择功能（键入1或者2）："<<endl
		    <<"1. 分数计算"<<endl
		    <<"2. 分数排序"<<endl
		    <<"3. 退出"<<endl
			<<"____\n"<<endl; 
		int m;
		cin>>m;
		cin.ignore();
	    if(m==1){
	    	system("cls");
			while(1){
				cout<<"请输入分数计算式（如1/2+1/3回车），输入#号键返回上一层目录：\n___\n";
				string s;
				getline(cin,s);
				if(s.empty()){
					cout<<"输入为空！"<<endl;
					clean();
					continue; 
				} else if(s=="#"){
					clean();
					break;
				}else{
					if(!first_count(s)){
						cout<<"分数算式输入错误！\n";
						clean();
						continue;
					}else{
						Fraction f=NB_count(s);
						int b=f.getDeno();
						if(b==0){
						    cout<<"分数算式输入错误！\n";
						    clean();
						    continue;
						}else{
							cout<<f<<endl;
							clean();
							continue; 
						}
					}
				}
					
			}
		}else if(m==2){
			system("cls");
			while(1){
				cout<<"请输入一组分数，用逗号隔开，如需由小到大排序用符号<结尾，\n"
				    <<"由大到小排序用符号>结尾（如1/2,1/4,3/5<回车），输入#号键返回\n"
					<<"上一层目录：\n____\n";
			    string s;
			    getline(cin,s);
			    if(s=="#"){
			    	clean();
					break;
				}else if(!right(s)){
					cout<<"输入错误！\n";
					clean();
					continue;
				}else{
					vector<Fraction> fractions;
	                int start = 0;	 
					int number=0;  	    
	                for (int i = start; i < s.length(); i++) {
	                    if (i == s.length()-1 || s[i] == ',' ) {
	                        string fra_str = s.substr(start, i - start);
	                        if (!fra_str.empty()) {
	                            fractions.push_back(str_to_fra(fra_str));
	                        }else{
			            	    cout<<"输入错误！\n";
			            	    clean();
			            	    continue;
		            		}	                        
	                        start = i + 1;
	                        number++;
	                    }
	                }		//输入分数
					int p=s.length()-1;	
					string s0(s,p,1);	
	                sortFraction(fractions,s0);
	                for(int i=0;i<number;i++){
						cout<<fractions[i]<<" ";
					}	 
					cout<<endl;
					clean();
					continue;             					   
				}
			} 
		}else{
			clean();
		    break;
		}
	}        
}
