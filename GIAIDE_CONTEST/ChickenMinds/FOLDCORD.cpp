#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define vec(type, a, size, value) vector<type> a(size, value);
#define all(x) x.begin(), x.end()
#define I_O(input_name, output_name) freopen((string(input_name) + ".inp").c_str(), "r", stdin); freopen((string(output_name) + ".out").c_str(), "w", stdout); fast;
#undef min
#undef max
#define min(a,b) std::min((ll)a, (ll)b)
#define max(a,b) std::max((ll)a, (ll)b)

bool multitest = false;

void init()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    fast;
}

bool isvalid_way(int l, int r, const vector<double>& a) // Ensure a remains unchanged
{
    //cout << " indices: l = " << l << ", r = " << r << endl;
    //cout << " values: a[l] = " << a[l] << ", a[r] = " << a[r] << endl;

    double middle = (a[l] + a[r]) / 2;
    //cout << "middle " << middle << endl;

    vector<double> temp = a;
    if (find(temp.begin(), temp.end(), middle) == temp.end()) 
    {
        temp.push_back(middle);
        //cout << "added" << endl;
    }
    else 
    {
        //cout << "skipped adding" << endl;
    }

    sort(temp.begin(), temp.end());

    //cout << temp:  ";
    //for (double num : temp) cout << num << " ";
    //cout << endl;

    auto it = lower_bound(temp.begin(), temp.end(), middle);
    int new_r = distance(temp.begin(), it) + 1;
    int new_l = distance(temp.begin(), it) - 1;
    int subr = new_r;
    int subl = new_l;

    //cout << "new_l = " << new_l << ", new_r = " << new_r << endl;

    while (new_l >= 0 && new_r < temp.size() && abs(temp[new_l] - middle) == abs(temp[new_r] - middle))
    {
        //cout << "valid!?!? temp[new_l] = " << temp[new_l] << ", temp[new_r] = " << temp[new_r] << endl;

        if (new_l - 1 >= 0 && new_r + 1 < temp.size() && abs(temp[new_l - 1] - middle) == abs(temp[new_r + 1] - middle))
        {
            new_l--;
            new_r++;
        }
        else
            break;
    }

    //cout << "expanded new_l = " << new_l << ", new_r = " << new_r << endl;
    if (new_l == 0 || new_r == temp.size() - 1)
    {
        //cout << "true=>return" << endl;
        return true;
    }
    if(abs(new_l - subr) == abs(new_r - subl) && new_l > 0 && new_r != temp.size()-1)
    {
        //cout<<"nhot"<<endl;
        return false;

    }

    double maxx_change = max(abs(temp[new_l] - middle), abs(temp[new_r] - middle));
    //cout << "max changed " << maxx_change << endl;

    bool left = maxx_change == abs(temp[new_l] - middle);
   // cout << "trai hay phai?" << (left ? "Left" : "Right") << endl;

    if (left)
    {
        for (int i = new_r; i < temp.size(); i++)
        {
            // << "Check phai, temp[i] = " << temp[i] << endl;
            if (abs(temp[i] - middle) > maxx_change)
            {
               // cout << "nhot do > maxchange" << endl;
                return false;
            }
        }
        //cout << "true." << endl;
        return true;
    }
    else
    {
        for (int i = new_l; i >= 0; i--)
        {
            //cout << "Chcheck left temp[i] = " << temp[i] << endl;
            if (abs(temp[i] - middle) > maxx_change)
            {
                //cout << "nhot do > maxchange" << endl;
                return false;
            }
        }
        //cout << "true" << endl;
        return true;
    }
}


void sol()
{
    int r, n;
    cin>>n>>r;
    vector<double> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    ll res = 0;
    set<double> cnt;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
           // cout<<"index "<<i<<" "<<j<<endl;
            if(isvalid_way(i, j, a))
            {
                //cout<<"hup "<<a[i]<<" "<<(a[i] + a[j])/2<<" "<<a[j]<<endl;
                cnt.insert((a[i] + a[j])/2);
            }
           // cout<<endl;
        }
    }
    //for(auto& i : cnt)cout<<i<<" ";
    //cout<<endl;
    cout<<cnt.size();
}

KING_PHAT
{
    // set state for multitest
    // multitest = true;
    // set state for I/O style
    // I_O("test1", "test1");
    fast;

    if (multitest)
    {
        int t;
        cin >> t;
        while (t--)
        {
            sol();
        }
    }
    else
    {
        sol();
    }

    return 0;
}
