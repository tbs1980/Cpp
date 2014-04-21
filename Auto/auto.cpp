#include <iostream>
#include <typeinfo>

template< class T, class U >
auto add(T t,U u) -> decltype (t+u)
{
	return t+u;
}

int main(void)
{
	auto i = 5;
	auto j = 5.5;
	auto k = j;
	auto a ="hello";
	auto b=add(i,i);
	
	return 0;
}
