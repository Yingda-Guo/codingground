#include <iostream>
#include <random>
#include <algorithm> 
#include <vector>

using namespace std;

int main()
{
    vector <int> v;
//Let's generate 1000 uniformly evenly distributed
    random_device rd;   // non-deterministic generator
    mt19937 gen(rd());  // to seed mersenne twister.
    uniform_int_distribution<> dist(0,1000); // distribute results between 1 and 6 inclusive.

    for (int i = 0; i < 120; ++i) 
    {
        v.push_back(dist(gen)); // pass the generator to the distribution.
    }
    
    sort (v.begin(), v.end());
    
      // using default comparison:
  std::vector<int>::iterator it;
  it = std::unique (v.begin(), v.end()); 
  
  cout << "How many left "<< std::distance(v.begin(),it) << endl;

  v.resize( std::distance(v.begin(),it) ); // 10 20 30 20 10

  // print out content:
  std::cout << "myvector contains:";
  for (it=v.begin(); it!=v.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

    return 0;
}

