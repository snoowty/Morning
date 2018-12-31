#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, imid;
    int count = 0;
    vector<int> v = {1,3,5,6,9,14,20,23,30,35,40,41,57,68,76,90};

    cin >> n;

    //二分探索 (繰り返しで実装)
    int imin;//最小
    int imax;//最大

    //ここから
    imin = 0;
    imax = v.size() - 1;

    while(imax >= imin) {
      count++;
      imid = imin + (imax - imin) / 2;
      if(v[imid] == n) break;
      else if(v[imid] > n) imax = imid - 1;
      else if(v[imid] < n) imin = imid + 1;
    }
    //ここまで

    if(imin <= imax){
        cout << "v[" << imid << "]　が " << n << "です。" << endl;//表示例
        cout << "比較回数は、" << count << "回" << endl;
    }else{
        cout << "NotFound" << endl;
        cout << "比較回数は、" << count << "回" << endl;
    }

}
