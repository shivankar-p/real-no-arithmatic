#include<bits/stdc++.h>

using namespace std;

int mfun(int i, int m)
{
    if(i < 0)   return m+(i%m);
    else return i%m;
}

vector<int> di(int x, int base)
{
    vector<int> ans;
    int q = x/base;
    int rem = x%base;
    if(rem < 0)
    {
        rem += base;
        q -= 1;
    }
    ans.push_back(q);
    ans.push_back(rem);

    return ans;
}

/*void addition(vector<int> a, vector<int> b, int base)
{
    int carry = 0;
    int x = a.size();
    int y = b.size();

    int i = x-1;
    int j = y-1;
    vector<int> ans;
    while(i >= 0 && j >= 0)
    {
        vector<int> res = di(a[i]+b[j]+carry, base);
        ans.push_back(res[1]);
        carry = res[0];
        i--;
        j--;
    }

    while(i >= 0)
    {
        vector<int> res = di(a[i]+carry, base);
        ans.push_back(res[1]);
        carry = res[0];
        i--;
    }

    while(j >= 0)
    {
        vector<int> res = di(b[j]+carry, base);
        ans.push_back(res[1]);
        carry = res[0];
        j--;
    }

    if(carry > 0)   ans.push_back(carry);
    reverse(ans.begin(), ans.end());
    for(i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }
    cout << endl;
}*/

/*vector<vector<int>> addition(vector<int> a, vector<int> b, int n, int m, int p1, int p2, int base)
{
    int carry = 0;
    int x = a.size();
    int y = b.size();
    int precision;

    
    int d1 = n - p1;
    int d2 = m - p2;
    if(d1 > d2)
    {
        vector<int> v2;
        for(int idx = 1; idx <= d1 - d2; idx++)
            v2.push_back(0);
        for(int idx = 0; idx < n; idx++)
            v2.push_back(b[idx]);
        copy(v2.begin(), v2.end(), b.begin());
    }
    else
    {
        vector<int> v1;
        for(int idx = 1; idx <= d2 - d1; idx++)
            v1.push_back(0);
        for(int idx = 0; idx < m; idx++)
            v1.push_back(a[idx]);
        copy(v1.begin(), v1.end(), a.begin());
    }
    cout << "a: ";
    for(int idx = 0; idx < a.size(); idx++)
        cout << a[idx] << " ";
    cout << endl << "b: ";
    for(int idx = 0; idx < b.size(); idx++)
        cout << b[idx] << " ";
    cout << endl;
    if(p1 > p2)
        precision = p1;
    else
        precision = p2;
    int i = x-1;
    int j = y-1;
    vector<int> ans;
    while(i >= 0 && j >= 0)
    {
        vector<int> res = di(a[i]+b[j]+carry, base);
        ans.push_back(res[1]);
        carry = res[0];
        i--;
        j--;
    }

    while(i >= 0)
    {
        vector<int> res = di(a[i]+carry, base);
        ans.push_back(res[1]);
        carry = res[0];
        i--;
    }

    while(j >= 0)
    {
        vector<int> res = di(b[j]+carry, base);
        ans.push_back(res[1]);
        carry = res[0];
        j--;
    }

    if(carry > 0)   ans.push_back(carry);
    reverse(ans.begin(), ans.end());
    for(i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if(i == ans.size() - precision - 1)
            cout << ".";
    }
    vector<vector<int>> ret;
    ret.push_back(ans);
    vector<int> pres_arry = {(int)ans.size()-precision-1};
    ret.push_back(pres_arry);
    cout << endl;
    return ret;
}*/

/*vector<vector<int>> addition(vector<int> inp1, vector<int> inp2, int n, int m, int p1, int p2, int base)
{
    
    int f_sz = inp1.size();
    int s_sz = inp2.size();
    vector<int> a(max(f_sz, s_sz), 0), b(max(f_sz, s_sz), 0);
    for(int i = 0; i < f_sz; i++)   a[i] = inp1[i];
    for(int i = 0; i < s_sz; i++)   b[i] = inp2[i];
    int carry = 0;
    int x = a.size();
    int y = b.size();
    int precision;

    
    int d1 = n - p1;
    int d2 = m - p2;
    if(d1 > d2)
    {
        vector<int> v2;
        for(int idx = 1; idx <= d1 - d2; idx++)
            v2.push_back(0);
        for(int idx = 0; idx < n; idx++)
            v2.push_back(b[idx]);
        copy(v2.begin(), v2.end(), b.begin());
    }
    else
    {
        vector<int> v1;
        for(int idx = 1; idx <= d2 - d1; idx++)
            v1.push_back(0);
        for(int idx = 0; idx < m; idx++)
            v1.push_back(a[idx]);
        copy(v1.begin(), v1.end(), a.begin());
    }
    
    if(p1 > p2)
    {
        precision = p1;
    }
    else
    {
        precision = p2;
    }
    int i = x-1;
    int j = y-1;
    

    vector<int> ans;
    while(i >= 0 && j >= 0)
    {
        vector<int> res = di(a[i]+b[j]+carry, base);
        ans.push_back(res[1]);
        carry = res[0];
        i--;
        j--;
    }

  
    while(i >= 0)
    {
        vector<int> res = di(a[i]+carry, base);
        ans.push_back(res[1]);
        carry = res[0];
        i--;
    }

    while(j >= 0)
    {
        vector<int> res = di(b[j]+carry, base);
        ans.push_back(res[1]);
        carry = res[0];
        j--;
    }

    if(carry > 0)   ans.push_back(carry);
    reverse(ans.begin(), ans.end());
    for(i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if(i == ans.size() - precision - 1)
            cout << ".";
    }
    cout << endl;

    ;
    vector<vector<int>> ret;
    ret.push_back(ans);
    vector<int> pres_arry = {(int)ans.size()-precision-1};
    ret.push_back(pres_arry);

    return ret;
}*/

vector<vector<int>> addition(vector<int> inp1, vector<int> inp2, int n, int m, int p1, int p2, int base)
{
    int f_sz = inp1.size();
    int s_sz = inp2.size();
    vector<int> a(f_sz+s_sz, 0), b(f_sz+s_sz, 0);
    for(int i = 0; i < f_sz; i++)   a[i] = inp1[i];
    for(int i = 0; i < s_sz; i++)   b[i] = inp2[i];
    int carry = 0;
    int x = a.size();
    int y = b.size();
    int precision;

    
    int d1 = n - p1;
    int d2 = m - p2;
    if(d1 > d2)
    {
        vector<int> v2;
        for(int idx = 1; idx <= d1 - d2; idx++)
            v2.push_back(0);
        for(int idx = 0; idx < n; idx++)
            v2.push_back(b[idx]);
        copy(v2.begin(), v2.end(), b.begin());
        precision = d1;
    }
    else
    {
        vector<int> v1;
        for(int idx = 1; idx <= d2 - d1; idx++)
            v1.push_back(0);
        for(int idx = 0; idx < m; idx++)
            v1.push_back(a[idx]);
        copy(v1.begin(), v1.end(), a.begin());
        precision = d2;
    }
    cout << precision << endl;
    cout << "a: ";
    for(int idx = 0; idx < a.size(); idx++)
        cout << a[idx] << " ";
    cout << endl << "b: ";
    for(int idx = 0; idx < b.size(); idx++)
        cout << b[idx] << " ";
    cout << endl;
    /*if(p1 > p2)
        precision = p1;
    else
        precision = p2;*/
    int i = x-1;
    int j = y-1;
    vector<int> ans;
    while(i >= 0 && j >= 0)
    {
        vector<int> res = di(a[i]+b[j]+carry, base);
        ans.push_back(res[1]);
        carry = res[0];
        i--;
        j--;
    }

    while(i >= 0)
    {
        vector<int> res = di(a[i]+carry, base);
        ans.push_back(res[1]);
        carry = res[0];
        i--;
    }

    while(j >= 0)
    {
        vector<int> res = di(b[j]+carry, base);
        ans.push_back(res[1]);
        carry = res[0];
        j--;
    }

    if(carry > 0)   ans.push_back(carry);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << " " << f_sz+s_sz << endl;
    for(i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if(i == precision-1 && ans.size() == f_sz+s_sz)
            cout << ".";
        else if(i == precision && ans.size() > f_sz+s_sz) cout << ".";
    }
    cout << endl;

    vector<vector<int>> ret;
    ret.push_back(ans);
    if(ans.size() == f_sz+s_sz) ret.push_back({(int)ans.size()-precision});
    else ret.push_back({(int)ans.size()-precision});

    return ret;
}

void subtraction(vector<int> a, vector<int> b, int base)
{
    int carry = 0;
    int x = a.size();
    int y = b.size();

    int i = x-1;
    int j = y-1;
    vector<int> ans;
    while(i >= 0 && j >= 0)
    {
        vector<int> res = di(a[i]-b[j]+carry, base);
        if(b[j]+carry > a[i]) carry = -1;
        else carry = 0;
        ans.push_back(res[1]);
        i--;
        j--;
        cout << carry << endl;
    }

    while(i >= 0)
    {
        vector<int> res = di(a[i]+carry, base);
        ans.push_back(res[1]);
        carry = 0;
        i--;
        cout << carry << endl;
    }

    while(j >= 0)
    {
        vector<int> res = di(b[j]+carry, base);
        ans.push_back(res[1]);
        carry = -1;
        j--;
        cout << carry << endl;
    }

    if(carry == -1) ans.push_back(0);
    
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++)
    {
        if(i == 0 && ans[i] == 0)   cout << "-";
        else cout << ans[i];
    }
    cout << endl;
}

/*void multiply(vector<int> a, vector<int> b, int base)
{
    int x = a.size();
    int y = b.size();
    int carry;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    vector<int> ans(x+y, 0);
    for(int i = 0; i < x; i++)
    {
        carry = 0;
        for(int j = 0; j < y; j++)
        {
            vector<int> res = di((a[i]*b[j])+ans[i+j]+carry, base);
            carry = res[0];
            ans[i+j] = res[1];
        }
        ans[i+y] = carry;
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < x+y; i++)
    {
        cout << ans[i];
    }

    cout << endl;
}*/

vector<vector<int>> multiply(vector<int> inp1, vector<int> inp2, int n, int m, int p1, int p2, int base)
{
    int f_sz = inp1.size();
    int s_sz = inp2.size();
    vector<int> a(max(f_sz,s_sz), 0), b(max(f_sz,s_sz), 0);
    for(int i = 0; i < f_sz; i++)   a[i] = inp1[i];
    for(int i = 0; i < s_sz; i++)   b[i] = inp2[i];
    
    int x = a.size();
    int y = b.size();
    int carry;
    int precision = p1 + p2;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    vector<int> ans(x+y, 0);
    for(int i = 0; i < x; i++)
    {
        carry = 0;
        for(int j = 0; j < y; j++)
        {
            vector<int> res = di((a[i]*b[j])+ans[i+j]+carry, base);
            carry = res[0];
            ans[i+j] = res[1];
        }
        ans[i+y] = carry;
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < x+y; i++)
    {
        cout << ans[i];
        if(i == (x + y - 1 - precision - abs(n - m)))
            cout << ".";
    }

    cout << endl;

    cout << x + y - 1 - precision - abs(n - m) << " mul point\n";

    vector<vector<int>> res;
    res.push_back(ans);
    int pres_no = x + y - 1 - precision - abs(n - m);
    pres_no = ans.size()-pres_no;
    res.push_back({pres_no});

    cout << endl;

    return res;
}

vector<int> div_int(vector<int> a, vector<int> b, int base)
{
    for(int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }

    cout << endl;
    int k = a.size();
    int l = b.size();
    int carry;
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    vector<int> r(k+1), q(k-l+1, 0);
    for(int i = 0; i <= k-1; i++)   r[i] = a[i];
    r[k] = 0;

    

    for(int i = k-l; i>=0; i--)
    {
        q[i] = floor(((r[i+l]*base)+r[i+l-1])/(b[l-1]*1.0));

        if(q[i] >= base) q[i] = base-1;

        carry = 0;

        for(int j = 0; j <= l-1; j++)
        {
            int x = r[i+j]-(q[i]*b[j])+carry;
            vector<int> res = di(x, base);
            carry = res[0];
            r[i+j] = res[1];
        }

        r[i+l] += carry;

        while(r[i+l] < 0)
        {
            carry = 0;
            for(int j = 0; j <= l-1; j++)
            {
                int x = r[i+j]+b[j]+carry;
                vector<int> res = di(x, base);
                carry = res[0];
                r[i+j] = res[1];
            }

            r[i+l] += carry;
            q[i] = q[i]-1;
        }
    }

    reverse(q.begin(), q.end());


    for(int i = 0; i < k-l+1; i++)
    {
        cout << q[i] << " ";
    }
    cout << endl;

    return q;
}

vector<vector<int>> division(vector<int> a, vector<int> b, int base, int req_pres, int p1, int p2)
{
    int k = a.size();
    int l = b.size();
    int carry;


    for(int i = 0; i < a.size(); i++)   cout << a[i] << " ";
    cout << endl;

    for(int i = 0; i < b.size(); i++)   cout << b[i] << " ";
    cout << endl;
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    


    vector<int> r(k+1), q(k-l+1, 0);
    for(int i = 0; i <= k-1; i++)   r[i] = a[i];
    r[k] = 0;

    

    for(int i = k-l; i>=0; i--)
    {
        q[i] = floor(((r[i+l]*base)+r[i+l-1])/(b[l-1]*1.0));

        if(q[i] >= base) q[i] = base-1;

        carry = 0;

        for(int j = 0; j <= l-1; j++)
        {
            int x = r[i+j]-(q[i]*b[j])+carry;
            vector<int> res = di(x, base);
            carry = res[0];
            r[i+j] = res[1];
        }

        r[i+l] += carry;

        while(r[i+l] < 0)
        {
            carry = 0;
            for(int j = 0; j <= l-1; j++)
            {
                int x = r[i+j]+b[j]+carry;
                vector<int> res = di(x, base);
                carry = res[0];
                r[i+j] = res[1];
            }

            r[i+l] += carry;
            q[i] = q[i]-1;
        }
    }

    reverse(q.begin(), q.end());

    int point = q.size()+p2-p1;
    

    vector<int> q_res;
    int ind = 0;
    //while(q[ind] == 0)    ind++;
    for(; ind < q.size(); ind++)   q_res.push_back(q[ind]);
    vector<int> r_res;
    for(int i = l-1; i >= 0; i--)   r_res.push_back(r[i]);
    for(int i = 0; i < req_pres; i++)   r_res.push_back(0);

    reverse(b.begin(), b.end());

    vector<int> q_fin = div_int(r_res, b, base);


    for(int i = 1; i < q_fin.size(); i++)  q_res.push_back(q_fin[i]);

    cout << "final quotient\n " << point << endl;

    if(point <= 0)
    {
        cout << "0 . ";
        for(int i = 0; i < -point; i++) cout << "0 ";
    }
    
    
    for(int i = 0; i< q_res.size(); i++)
    {
        if(i == point && i > 0)  cout << ". ";
        cout << q_res[i] << " ";
    }
    cout << endl;


   /* for(int i = l-1; i >= 0 ; i--)
    {
        cout << r[i];
    }*/ //actual rem

    for(int i = 0; i < r.size(); i++)
    {
        cout << r[i] << " ";
    }

    cout << endl;

    vector<vector<int>> ret;
    vector<int> pt_arr = {point};
    ret.push_back(q_res);
    ret.push_back(pt_arr);
    return ret;
}

void square_root(vector<int> a, int p, int base)
{
    vector<vector<int>> x;
    x.push_back(a);
    x.push_back({p});
    vector<vector<int>> dv, ad, y;
    vector<vector<int>> half;
    half.push_back({0, 5});
    half.push_back({1});

    

    cout << "sqrt test1\n";
    for(int i = 0; i < 10; i++)
    {
        cout << "sqrt x: \n";
        for(int p = 0; p < x[0].size(); p++)    cout << x[0][p] << " ";
        cout << endl;

        dv = division(a, x[0], base, 10, p, x[1][0]);

        if(dv[1][0] > 0)
        {
            dv[1][0] = dv[0].size()-dv[1][0];
        }
        else
        {
            vector<int> tmp;
            for(int ind = 0; ind <= -dv[1][0]; ind++) tmp.push_back(0);
            
            for(int ind = 0; ind < dv[0].size(); ind++) tmp.push_back(dv[0][ind]);
            dv[0].clear();
            copy(tmp.begin(), tmp.end(), dv[0].begin());
            dv[1][0] = tmp.size()-1;
        }
        cout << "dv val\n";
        for(int p = 0; p < dv[0].size(); p++)   cout << dv[0][p] << " ";
       
        cout << endl;
        cout << "dv point " << dv[1][0] << endl;

        ad = addition(x[0], dv[0], x[0].size(), dv[0].size(), x[1][0], dv[1][0], base);

        cout << "add val\n";
        for(int p = 0; p < ad[0].size(); p++)   cout << ad[0][p] << " ";
       
        cout << endl;

        cout << "ad point: " << ad[1][0] << endl;
        //cout << "add point " << ad[1][0] << endl;
        
        y = multiply(half[0], ad[0], half[0].size(), ad[0].size(), half[1][0], ad[1][0], base);

        vector<int> new_arr;

        int idx = y[0].size()-1;
        int cnt = 0;
        while(idx >= 0 && cnt < y[1][0] && y[0][idx] == 0)
        {
            idx--;
            cnt++;
        }

        cout << "idx " << idx << endl;

        for(int p = 0; p <= idx; p++)   new_arr.push_back(y[0][p]);
        y[0] = new_arr;
        y[1][0] -= (cnt+1);
        cout << "cnt: " << cnt << endl;
        

        copy(y.begin(), y.end(), x.begin());

        cout << "hi\n";

        cout << "mul value\n";
        for(int p = 0; p < y[0].size(); p++)    cout << y[0][p] << " ";
        cout << endl;
        cout << "mul pt " << y[1][0] << endl;
    }
    cout << "sqrt test2\n";
    cout << "root: ";
    for(int i = 0; i < y[0].size(); i++)    cout << y[0][i] << " ";
    cout << endl;
    cout << "root point: " << y[1][0] << endl;
}

int main()
{
    int n, p1;
    cin >> n >> p1;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }


    //division(a, b, 10, 8, p1, p2);
    square_root(a, p1, 10);
    
    cout << endl;
    return 0;
}