vector <ll> A_;
  vector <ll> T_;

  auto Build_ = [&] (ll Node_, ll Start_, ll End_, auto Build_) -> void{
    if(Start_ == End_) {
      T_[Node_] = A_[Start_];
      return;
    }
    ll Mid_ = (Start_ + End_) / 2;
    ll L_ = 2 * Node_ + 1;
    ll R_ = 2 * Node_ + 2;
    Build_ (L_, Start_, Mid_, Build_);
    Build_ (R_, Mid_ + 1, End_, Build_);
    T_[Node_] = min(T_[L_], T_[R_]);
  };

  auto Update_ = [&] (ll Node_, ll Start_, ll End_, ll Id_, ll Val_, auto &Update_) -> void {
    if(Start_ == End_) {
      A_[Id_] = Val_;
      T_[Node_] = Val_;
    }
    else {
      ll Mid_ = (Start_ + End_) / 2;
      ll L_ = 2 * Node_ + 1;
      ll R_ = 2 * Node_ + 2;
      if(Id_ >= Start_ && Id_ <= Mid_) {
        Update_ (L_, Start_, Mid_, Id_, Val_, Update_);
      }
      else {
        Update_ (R_, Mid_ + 1, End_, Id_, Val_, Update_);
      }
      T_[Node_] = min(T_[L_], T_[R_]);
    }
  };

  auto Query_ = [&] (ll Node_, ll Start_, ll End_, ll L, ll R , auto &Query_) {
    if(Start_ > R || End_ < L) {
      return LLONG_MAX;
    }
    if(Start_ >= L && End_ <= R) {
      return T_[Node_];
    }
    ll Mid_ = (Start_ + End_) / 2;
    ll L_ = 2 * Node_ + 1;
    ll R_ = 2 * Node_ + 2;
    ll LQ_ = Query_ (L_, Start_, Mid_, L, R, Query_);
    ll RQ_ = Query_ (R_, Mid_ + 1, End_, L, R, Query_);
    return min (LQ_, RQ_);
  };

  A_ = A;
  T_.resize(4 * n);
  Build_ (0, 0, n - 1, Build_);
