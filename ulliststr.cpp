#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val)
{

  if(empty()){
    Item* newItem = new Item();
    newItem->val[newItem->first]= val;
    newItem->last = 1;
    head_ = newItem;
    tail_ = newItem;
    size_++;
  }
  else if (tail_->last == ARRSIZE) {
    Item* newItem = new Item();
    newItem->val[newItem->first]= val;
    newItem->last = 1;
    tail_->next = newItem;
    newItem->prev = tail_;
    tail_ = newItem;
    size_++;
  }
  else {
    tail_->last++;
    tail_->val[tail_->last-1] = val;
    size_++;
  }
  
}

void ULListStr::push_front(const std::string& val)
{

  if(empty()){
    Item* newItem = new Item();
    newItem->val[newItem->first]= val;
    newItem->last = newItem->first + 1;
    head_ = newItem;
    tail_ = newItem;
    size_++;
  }
  else if (head_->first == 0) {
    Item* newItem = new Item();
    newItem->val[ARRSIZE - 1]= val;
    newItem->first = ARRSIZE - 1;
    newItem->last = ARRSIZE;
    newItem->next = head_;
    head_->prev = newItem;
    head_ = newItem;
    size_++;
  }
  else {
    head_->first++;
    head_->val[head_->first] = val;
    size_++;
  }

  // if(head_ == nullptr){
  //   Item* newItem = new Item();
  //   if(head_ != nullptr) {
  //     head_->prev = newItem;
  //     newItem->next = head_;
  //   }
  //   else {
  //     tail_ = newItem;
  //   }
  //   head_ = newItem;
  // }

  // head_->first--;
  // head_->val[head_->first] = val;
  // size_++;

}

void ULListStr::pop_back()
{
  if (empty()) {
    return;
  }

  tail_->last++;

  if(tail_->first == tail_->last) {
    Item* tmp = tail_;
    tail_ = tail_->prev;
    if (tail_!=nullptr){
      tail_->next = nullptr;
    }
    else{
      head_ = nullptr;
    }
    delete tmp;
  }

  size_--;
}

void ULListStr::pop_front()
{
  if (empty()) {
    return;
  }

  head_->first++;

  if(head_->first == head_->last) {
    Item* tmp = head_;
    head_ = head_->next;
    if (head_!=nullptr){
      head_->prev = nullptr;
    }
    else{
    tail_ = nullptr;
    }
    delete tmp;
  }

  size_--;

}

std::string const & ULListStr::back() const
{
  if(!empty()){
    return tail_->val[tail_->last - 1];
  }

}

std::string const & ULListStr::front() const
{
  if(!empty()){
    return head_->val[head_->first];
  }

}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if(loc >= size_){
    return nullptr;
  }

  Item* curr = head_;
  size_t idx = loc;

  while(curr != nullptr){
    if(idx < curr->last - curr->first){
      return &curr->val[curr->first + idx];
    }
    idx -= curr->last - curr->first;
    curr = curr->next;
  }

  return nullptr;

}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
