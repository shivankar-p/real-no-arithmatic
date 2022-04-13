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

void addition(vector<int> inp1, vector<int> inp2, int n, int m, int p1, int p2, int base)
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
}

void subtraction(vector<int> a, vector<int> b, int n, int m, int p1, int p2, int base)
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

    int negative = 0;
    for(int idx = 0; idx < a.size(); idx++)
    {
        if(b[idx] > a[idx])
        {
            a.swap(b);
            negative = 1;
            break;
        }
    }
             
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
    }

    while(i >= 0)
    {
        vector<int> res = di(a[i]+carry, base);
        ans.push_back(res[1]);
        carry = 0;
        i--;
    }

    while(j >= 0)
    {
        vector<int> res = di(b[j]+carry, base);
        ans.push_back(res[1]);
        carry = -1;
        j--;
    }

    if(carry == -1) ans.push_back(0);
    
    reverse(ans.begin(), ans.end());
    if(negative)   cout << "-";
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if(i == ans.size() - precision - 1)
            cout << ".";
    }
    cout << endl;
}

void multiply(vector<int> a, vector<int> b, int n, int m, int p1, int p2, int base)
{
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
}

//vector<vector<int>> division_int(vector<int> a, vector<int> b, int base)
vector<int> division_int(vector<int> a, vector<int> b, int base)
{
    int k = a.size();
    int l = b.size();
    int carry;
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    vector<int> r(k+1), q(k-l+1, 0);
    for(int i = 0; i <= k-1; i++)   r[i] = a[i];
    r[k] = 0;

    cout << "hi\n";

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
            // cout << "hi1\n";
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
    //reverse(r.begin(), r.end());

    return q;

    //vector<vector<int>> qr;
    //qr.push_back(q);
    //qr.push_back(r);
    //return qr;
}

void division_float(vector<int> a, vector<int> b, int n, int m, int p1, int p2, int base, int req_precision)
{
    int k = a.size();
    int l = b.size();
    int carry;
    //int precision = p1 - p2;
    
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

    cout << "cmp: \n";

    for(int i = 0; i < r.size(); i++)
    {
        cout << r[i] << " ";
    }

    cout << endl;
    
    vector<int> r_transf;

    for(int i = l-1; i >= 0 ; i--)
    {
        r_transf.push_back(r[i]);
    }

    for(int i = l; i <= k; i++) r[i] = 0;

    cout << "a" << endl;

    for(int idx = 1; idx <= req_precision; idx++)
        r_transf.push_back(0);
    vector<int> q_res;
    cout << "b" << endl;
    for(int idx = 0; idx < q.size(); idx++)
        q_res.push_back(q[idx]);

    cout << "r: ";
    for(int i = 0; i < r_transf.size(); i++)   cout << r_transf[i] << " ";
    cout << endl;
    vector<int> q_rem = division_int(r_transf, b, base);

    

    for(int idx = 0; idx < q_rem.size(); idx++)
        q_res.push_back(q_rem[idx]);
    
    //qr_res = division_int(r, b, base);
    
    //qr_res.push_back();
    for(int i = 0; i < q_res.size(); i++)
    {
        cout << q_res[i];
    }
    cout << endl;

/*
    for(int i = l-1; i >= 0 ; i--)
    {
        cout << qr_res[1][i];
    }

    cout << endl;
*/
}

int main()
{
    int n, m, p1, p2;
    cout << "Enter length of 2 numbers";
    cin >> n >> m;
    cout << "Enter precision of 2 numbers";
    cin >> p1 >> p2;
    vector<int> a(max(n, m), 0), b(max(n, m), 0);
    cout << "Enter 2 numbers";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    addition(a, b, n, m, p1, p2, 10);
    
    cout << endl;
    return 0;
}