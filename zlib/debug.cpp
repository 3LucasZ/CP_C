using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string &s)
{
  return '"' + s + '"';
}

string to_string(const char *s)
{
  return to_string((string)s);
}

string to_string(char s)
{
  string s1{s};
  return s1;
}

string to_string(bool b)
{
  return (b ? "true" : "false");
}

string to_string(vector<bool> v)
{
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++)
  {
    if (!first)
    {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

string to_string(priority_queue<int> v)
{
  priority_queue<int> copy = priority_queue(v);
  bool first = true;
  string res = "{";
  while (!copy.empty())
  {
    if (!first)
    {
      res += ", ";
    }
    first = false;
    res += to_string(copy.top());
    copy.pop();
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v)
{
  string res = "";
  for (size_t i = 0; i < N; i++)
  {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(A v)
{
  bool first = true;
  string res = "{";
  for (const auto &x : v)
  {
    if (!first)
    {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p)
{
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p)
{
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p)
{
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef DEBUG
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
// uncomment to turn off
// #define dbg(...) 42
#else
#define dbg(...) 42
#endif

using namespace std::chrono;
auto start = high_resolution_clock::now();
void printTime()
{
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);
  cout << duration.count() << " ms" << endl;
  start = stop;
}