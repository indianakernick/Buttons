//
//  digit stack.hpp
//  Buttons
//
//  Created by Indi Kernick on 29/11/17.
//  Copyright © 2017 Indi Kernick. All rights reserved.
//

#ifndef digit_stack_hpp
#define digit_stack_hpp

template <typename Value_, Value_ BASE = 10>
class DigitStack {
public:
  using Value = Value_;

  DigitStack() = default;
  explicit DigitStack(const Value val)
    : val(val) {}
  
  void push(const Value digit) {
    val = val * BASE + digit;
    ++numDigits;
  }
  void pop() {
    val /= BASE;
    if (numDigits != 0) {
      --numDigits;
    }
  }
  void clear() {
    val = 0;
    numDigits = 0;
  }
  
  Value get() const {
    return val;
  }
  bool empty() const {
    return numDigits == 0;
  }
  
private:
  Value val = 0;
  unsigned char numDigits = 0;
};

#endif
