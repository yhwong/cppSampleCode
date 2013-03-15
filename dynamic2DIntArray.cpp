#include <iostream>
using namespace std;

class IntArr{
  int* _data;
  unsigned int _size;
public:
  IntArr(unsigned int size){
    _data = new int[_size = size];
  }
  int& operator[](unsigned int index){
    if(index >= _size){
      unsigned int newsize =  index < 1024 ? index*2 : index + 1024;
      int* temp = new int[newsize];
      for(int i=0;i<_size;i++){
        temp[i] = _data[i];
      }
      delete[] _data;
      _data = temp;
      _size = newsize;
    }
    return _data[index];
  }

  unsigned int Size()const{
    return _size;
  }
  virtual ~IntArr(){
    if(_data){
      delete[] _data; // if it makes you happy
    }
  }
};



class IntArrArr{
  IntArr** _data;
  unsigned int _size;
  unsigned int _width; 
public:
  IntArrArr(unsigned int size,unsigned int width){
    _data = new IntArr*[_size = size];
    for(int i=0;i<size;i++){
      _data[i] = (IntArr*)0;
    }
    _width = width;
  }
  IntArr& operator[](unsigned int index){
	  IntArr** temp;
	  if (index >= _size){
		int i;
		
        //Step 1: Make a temporary array with a new size
		unsigned int newsize = index < 1024? index*2 : index + 1024;
		temp = new IntArr* [newsize];

        //Step 2: Null each element of the temporary array
        for (i = 0; i < (int)newsize; i++){
			temp[i] = 0;
		}

		//Step 3: Copy data from the old array to the temporary array 
		for (i = 0; i < _size; i++){
			temp[i] = _data[i];
		}
        //Step 4: Add a new array to the next avaliable index
        temp[i] = new IntArr(_width);
        
        //Step 5: Delete the old array
        delete [] _data;
        
        //Step 6: Update the size and have data pointer point to the temporary array   
		_size = newsize;
		_data = temp;
	}
    else if(_data[index] == 0){
      _data[index] = new IntArr(_width);
    }
    return *_data[index];
  }

  unsigned int Size()const{
    return _size;
  }
  virtual ~IntArrArr(){
    for(int i=0;i<_size;i++){
      if(_data[i]){
        delete _data[i];
      }
    }
    delete[] _data;
  }
};


int main(){
  IntArrArr I(5, 4);
  
  int i;
  int j;
  for(i=0;i<6;i++){
    for(j=0;j<4;j++){
      I[i][j] = (i+1) * (j+1);
    }
  }
  for(i=0;i<5;i++){
    for(j=0;j<4;j++){
      cout<<I[i][j]<< " ";
    }
    cout<<endl;
  }
  getchar();
  return 0;
}


