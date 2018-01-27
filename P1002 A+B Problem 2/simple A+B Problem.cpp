#include <iostream>
#include <vector>
#include <algorithm>

class BigInteger:public std::vector<char>{
private:
    typedef std::vector<char> super;
public:
    BigInteger (){};
    BigInteger (const char* a){
        super buf;
        clear();
        for (const char *c=a;*c!=0;c++) buf.push_back(*c);
        insert(begin(),buf.rbegin(),buf.rend());
    }
    //C++11特性，移动构造函数
    BigInteger (super &&dat){
        swap (dat);
    }

    BigInteger operator+(const BigInteger& a) const{
        super ret;
        //need_append判断是否需要进位
        bool need_append=false;
        //j为长的list的迭代器，i为短的list的迭代器
        //此循环处理i与j的共有部分
        const auto cmp_size=[](const BigInteger& a,const BigInteger& b){
            return a.size()<b.size();
        };
        for (
            auto i=min(*this,a,cmp_size).begin(),j=max(a,*this,cmp_size).begin();
            j!=max(a,*this,cmp_size).end();j++)
        {
            ret.push_back(*j);
            if (i!=min(a,*this,cmp_size).end()){
                ret.back()+=*i - '0';
                ++i;
            }
            if (need_append) {
                ret.back()+=1;
                need_append=false;
            }
            if (ret.back()>'9'){
                ret.back()-=10;
                need_append=true;
            }
        }
        //返回的时候使用move降低消耗
        return BigInteger(move(ret));
    }
    BigInteger operator+(BigInteger &&a) const{
        auto i=begin();
        bool need_append=false;
        for (auto j=0;j!=a.size();){
            if (i!=end()){
                a[j]+=*i-'0';
                ++i;
            }
            //进位处理
            if (need_append){
                a[j]+=1;
                need_append=false;
            }
            //进位登记
            if (a[j]>'9'){
                need_append=true;
                a[j]-=10;
            }
            //如果j加完,i没加完或者需要进位，补0
            if (++j == a.size() && (i!=end() || need_append)){
                a.push_back('0');
            }
            //如果i加完且没有进位，跳出循环以优化运行速度
            if (i==end() && ! need_append) break;
        }
        return a;
    }

    const BigInteger& operator++(){return *this=*this+super{'1'};}

    friend std::istream& operator >> (std::istream& in,BigInteger &a);
    friend std::ostream& operator << (std::ostream& out,const BigInteger &a);
};

std::istream& operator >> (std::istream& in,BigInteger &a){
    a.clear();
    BigInteger::super buf;
    //第一个字符，消除前导空白与前导回车
    char c;
    in>>c;
    if (c != '0'){
        buf.push_back(c);
    }
    else{
        //去除前导0
        while ((c=in.get()) == '0' || c==' ' || c == EOF || c == '\n'){
            //全tm是0
            if (c==' ' || c == EOF || c == '\n'){
                a.push_back('0');
                return in;
            }
        }
        buf.push_back(c);
    }
    //后续字符的键入
    for (;(c=in.get()) != EOF && c!=' ' && c!='\n' ;){
        buf.push_back(c);
    }
    a.insert (a.begin(),buf.rbegin(),buf.rend());
    return in;
}
std::ostream& operator << (std::ostream& out,const BigInteger &a){
    for_each(a.rbegin(),a.rend(),[&out](char c){out<<c;});
    return out;
}

int main(int argc, char const *argv[]) {
    BigInteger a,b;
    std::cin>>a>>b;
    std::cout<<a+b<<std::endl;
    return 0;
}
