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

void addition(vector<int> a, vector<int> b, int base)
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

void multiply(vector<int> a, vector<int> b, int base)
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
}

void division(vector<int> a, vector<int> b, int base)
{
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

    for(int i = 0; i<=k-l; i++)
    {
        cout << q[i];
    }
    cout << endl;


   /* for(int i = l-1; i >= 0 ; i--)
    {
        cout << r[i];
    }*/ //actual rem

    for(int i = l-1; i >= 0; i--)
    {
        cout << r[i] << " ";
    }

    cout << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    division(a, b, 10);
    
    cout << endl;
    return 0;
}