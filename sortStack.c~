sort the stack

stack sort(stac s)
{
  stack r;
  while(s.empty==false)
  {
    tmp = s.pop();
    while(r.empty != false && tmp < r.top())
      s.push(r.pop());
    
    r.push(tmp);
  }
  return r;
}
