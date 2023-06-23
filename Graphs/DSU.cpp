auto Make_Node = [&] (ll x) -> void {
    Par_[x] = x;
    Size_[x] = 1;
    Comp[x].push_back(x);
  };

  auto Find_Par = [&] (ll x, auto &Find_Par) -> ll {
    if(Par_[x] == x) return x;
    else return Par_[x] = Find_Par(Par_[x], Find_Par);
  };

  auto Merge_Node = [&] (ll a, ll b) -> void {
    a = Find_Par(a, Find_Par);
    b = Find_Par(b, Find_Par);
    if(Size_[a] < Size_[b]) swap(a, b);
    Par_[b] = a;
    Size_[a] += Size_[b];
  };
