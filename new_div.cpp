#include<bits/stdc++.h>
#define int long long

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

    cout << "hio" << endl;
    cout << q << " " << rem << endl;

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

vector<int> div_int(vector<int> a, vector<int> b, int base)
{
    cout << "test\n";
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

    cout << "test q\n";

    for(int i = 0; i < k-l+1; i++)
    {
        cout << q[i] << " ";
    }
    cout << endl;

    return q;
}

void division(vector<int> a, vector<int> b, int base, int req_pres, int p1, int p2)
{
    int k = a.size();
    int l = b.size();
    int carry;
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    vector<int> r(k+1), q;
    for(int i = 0; i <= k-1; i++)   r[i] = a[i];
    r[k] = 0;

    for(int i = 0; i <= abs(k-l); i++)   q.push_back(0);

    

    for(int i = abs(k-l); i>=0; i--)
    {
        q[i] = floor(((r[i+l]*base)+r[i+l-1])/(b[l-1]*1.0));

        if(q[i] >= base) q[i] = base-1;

        carry = 0;

        for(int j = 0; j <= l-1; j++)
        {
            int x = r[i+j]-(q[i]*b[j])+carry;
            int qt = x/base;
            int rm = x%base;
            if(rm < 0)
            {
                rm += base;
                qt -= 1;
            }
            //vector<int> res = di(x, base);
            carry = qt;
            r[i+j] = rm;
        }

        r[i+l] += carry;

        while(r[i+l] < 0)
        {
            carry = 0;
            for(int j = 0; j <= l-1; j++)
            {
                int x = r[i+j]+b[j]+carry;
                //vector<int> res = di(x, base);
                int qt = x/base;
                int rm = x%base;
                if(rm < 0)
                {
                    rm += base;
                    qt -= 1;
                }
                //cout << "res: " << res[0] << " " << res[1] << endl;
                carry = qt;
                r[i+j] = rm;
            }

            r[i+l] += carry;
            q[i] = q[i]-1;
        }
    }

    reverse(q.begin(), q.end());

    cout << "in quo " << q.size() << endl;;

    for(int i = 0; i < q.size(); i++)   cout << q[i] << " ";
    cout << endl;

    int point = q.size()+p2-p1;
    cout << "size " << point << endl;

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
}

int32_t main()
{
    int n, m, p1, p2;
    cin >> n >> m >> p1 >> p2;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    division(a, b, 10, 8, p1, p2);
    
    cout << endl;
    return 0;
}