#include <iostream>
#include <string>

std::string s = "GGGGGGGGGGGGGGRRRRRRRRRRRRRRROOOOOOOOOOOOOOOTTTTTTTTTTEEEEEEEEEEEEEEKKKKKKKKSSSSSSSSSSSTTTTTTTTTAAAAAAAAAA";
int i = 10000000;
class cc{
	public:
		int a, b, c, d, e, f, g, h;
		std::string sa, sb, sc, sd, se;
		cc() :a(i), b(i), c(i), d(i), e(i), f(i), g(i), h(i), sa(s), sb(s),sc(s),sd(s),se(s) {}
			
			
	};

int main()
{
	bool a = true;
	cc* c2 = new cc{};
	
	std::cout << c2->a << std::endl;
	std::cout << c2->b << std::endl;
	std::cout << c2->c << std::endl;
	std::cout << c2->d << std::endl;
	std::cout << c2->e << std::endl;
	std::cout << c2->f << std::endl;
	std::cout << c2->g << std::endl;
	std::cout << c2->h << std::endl;
	std::cout << c2->sa << std::endl;
	std::cout << c2->sb << std::endl;
	std::cout << c2->sc << std::endl;
	std::cout << c2->sd << std::endl;
	std::cout << c2->se << std::endl;
	delete c2;
	std::cout << "\n\n\n";
	//kod da izmjeni vrijednosti delete-anog pointera koji ilegalno pristupa sada HEAP memoriji koja je prije bila STACK dok ju je on koristio
	
	
	while(a){
		cc* c1 = new cc{};
		if(c2->a != i || c2->b != i || c2->c != i || c2->d != i || c2->e != i || c2->f != i)
			a = false;
		if(c2->g != i ||  c2->h != i || c2->sa != s || c2->sb != s || c2->sc != s || c2->sd != s || c2->se != s)
			a=false;
		delete c1;
	}
	std::cout << c2->a << std::endl;
	std::cout << c2->b << std::endl;
	std::cout << c2->c << std::endl;
	std::cout << c2->d << std::endl;
	std::cout << c2->e << std::endl;
	std::cout << c2->f << std::endl;
	std::cout << c2->g << std::endl;
	std::cout << c2->h << std::endl;
	std::cout << c2->sa << std::endl;
	std::cout << c2->sb << std::endl;
	std::cout << c2->sc << std::endl;
	std::cout << c2->sd << std::endl;
	std::cout << c2->se << std::endl;
}
