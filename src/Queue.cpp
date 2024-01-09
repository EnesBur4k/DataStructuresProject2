/** 
* @file Queue.cpp
* @description Kuyruk veri yapısını oluşturur.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 25.12.2022
* @author enes.kaya11@ogr.sakarya.edu.tr
*/

#include "Queue.hpp"
using namespace std;

Queue::Queue(){
	first=0;
	last=-1;
	capacity = 50;
	length=0;			
	array = new int[capacity];
}
void Queue::reserve(int newCapacity){
			int *temp = new int[newCapacity];
			for(int i=first,j=0;j<length; j++){
				temp[j] = array[i]; 
				i = (i + 1) % capacity;
			}
			capacity = newCapacity;
			delete[] array;
			array = temp;
			first = 0;
			last = length - 1;
		}
bool Queue::isEmpty()
{
	if(length == 0) return true;
	return false;
}
int Queue::count()
{
	return length;
}
void Queue::clear()
{			
	first=0;
	last=-1;
	length=0;
}
const int& Queue::peek()
{
	if(isEmpty()) throw "Bos Liste";
	return array[first];
}
void Queue::enqueue(const int& item){
	if(length == capacity) reserve(2*capacity);
	last = (last + 1) % capacity;
	array[last] = item;
	length++;
}
void Queue::dequeue(){
	if(isEmpty()) throw "Bos Liste";			
	first = (first + 1) % capacity;
	length--;
}
Queue::~Queue(){
	delete[] array;
}		