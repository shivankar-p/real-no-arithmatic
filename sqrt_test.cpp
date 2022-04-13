#include<bits/stdc++.h>

using namespace std;
/*
int mfun(int i, int m)
{
    if(i < 0)   return m+(i%m);
    else return i%m;
}
*/

vector<int> RemovePaddingFromStart(vector<int> num, int precision_num)
{
    int scale = num.size() - precision_num;
    vector<int>::iterator it = num.begin();
    while((*it == 0) && (scale !=  1))
    {
        vector<int>::iterator cur = it;
        it = num.erase(cur);
        scale--;
    }
    return num;
}

vector<int> RemovePaddingFromEnd(vector<int> num, int *precision_num)
{
    while((num[num.size() - 1] == 0) && ((*precision_num) != 0))
    {
        num.pop_back();
        (*precision_num) = (*precision_num) - 1;
    }
    
    return num;
}

vector<int> QuoRem(int dividend, int divisor)
{
    vector<int> res;
    
    int quotient = dividend / divisor;
    int remainder = dividend % divisor;
    
    if(remainder < 0)
    {
        remainder = remainder + divisor;
        quotient = quotient - 1;
    }
    
    res.push_back(quotient);
    res.push_back(remainder);

    return res;
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

// limitations:
// works for usigned representation : a and b
vector<vector<int>> addition(vector<int> a, vector<int> b, int p1, int p2, int base)
{
    int k = a.size();
    int l = b.size();
    
    int precision_sum;
    
    if(p1 > p2)
    {
        for(int idx = 1; idx <= p1 - p2; idx++)
        {
            b.push_back(0);
            l++;
        }
        precision_sum = p1;
        
    }
    else
    {
        for(int idx = 1; idx <= p2 - p1; idx++)
        {
            a.push_back(0);
            k++;
        }
        precision_sum = p2;
        
    }
    
    int carry = 0;
    
    cout << "a: ";
    for(int idx = 0; idx < k; idx++)
        cout << a[idx] << " ";
    cout << endl << "b: ";
    for(int idx = 0; idx < l; idx++)
        cout << b[idx] << " ";
    cout << endl;
    
    int i = k - 1;
    int j = l - 1;
    
    vector<int> sum, quo_rem;
    
    while(i >= 0 && j >= 0)
    {
        quo_rem = QuoRem(a[i] + b[j] + carry, base);
        
        carry = quo_rem[0];
        sum.push_back(quo_rem[1]);
        
        i--;
        j--;
    }

    while(i >= 0)
    {
        quo_rem = QuoRem(a[i] + carry, base);
        
        carry = quo_rem[0];
        sum.push_back(quo_rem[1]);
        
        i--;
    }

    while(j >= 0)
    {
        quo_rem = QuoRem(b[j] + carry, base);
        
        carry = quo_rem[0];
        sum.push_back(quo_rem[1]);
        
        j--;
    }

    if(carry > 0)
         sum.push_back(carry);
    
    reverse(sum.begin(), sum.end());
    
    cout << "Sum before remove padding: ";
    for(i = 0; i < sum.size(); i++)
        cout << sum[i] << " ";
    cout << endl;
    
    //sum = RemovePaddingFromStart(sum, precision_sum);
    sum = RemovePaddingFromEnd(sum, &precision_sum);
    
    cout << "Sum after remove padding: ";
    for(i = 0; i < sum.size(); i++)
        cout << sum[i] << " ";
    cout << endl;
    
    for(i = 0; i < sum.size(); i++)
    {
        cout << sum[i];
        if((precision_sum != 0) && (i == sum.size() - precision_sum - 1))
            cout << ".";
    }
    
    vector<vector<int>> ret;
    ret.push_back(sum);
    vector<int> pres_arry = {(int)sum.size()-precision_sum-1};
    ret.push_back(pres_arry);
    cout << endl;
    return ret;
}

// limitations:
// works for usigned representation : a and b
// works for a >= b i.e. returns correct if a - b >= 0 and hence doesn't work for ((a.size() < b.size()) || ((a.size() == b.size()) && (a[0] < b[0])))
vector<vector<int>> subtraction(vector<int> a, vector<int> b, int p1, int p2, int base)
{
    /*
    if((a.size() < b.size()) || ((a.size() == b.size()) && (a[0] < b[0])))
        a.swap(b);
    */
    int k = a.size();
    int l = b.size();
    
    int precision_diff;
    
    if(p1 > p2)
    {
        for(int idx = 1; idx <= p1 - p2; idx++)
        {
            b.push_back(0);
            l++;
        }
        precision_diff = p1;
        
    }
    else
    {
        for(int idx = 1; idx <= p2 - p1; idx++)
        {
            a.push_back(0);
            k++;
        }
        precision_diff = p2;
        
    }
    
    int carry = 0;
    
    cout << "a: ";
    for(int idx = 0; idx < k; idx++)
        cout << a[idx] << " ";
    cout << endl << "b: ";
    for(int idx = 0; idx < l; idx++)
        cout << b[idx] << " ";
    cout << endl;
    
    int i = k - 1;
    int j = l - 1;
    
    vector<int> diff, quo_rem;
    
    while(i >= 0 && j >= 0)
    {
        quo_rem = QuoRem(a[i] - b[j] + carry, base);
        
        carry = quo_rem[0];
        diff.push_back(quo_rem[1]);
        
        i--;
        j--;
    }

    while(i >= 0)
    {
        quo_rem = QuoRem(a[i] + carry, base);
        
        carry = quo_rem[0];
        diff.push_back(quo_rem[1]);
        
        i--;
    }
    /*
    // modify for signed representation
    while(j >= 0)
    {
        quo_rem = QuoRem(b[j] + carry, base);
        
        carry = quo_rem[0];
        diff.push_back(quo_rem[1]);
        
        j--;
    }
    */
    //if(carry > 0)
    //     diff.push_back(carry);
    
    reverse(diff.begin(), diff.end());
    
    //diff = RemovePaddingFromStart(diff, precision_diff);
    diff = RemovePaddingFromEnd(diff, &precision_diff);
    
    for(i = 0; i < diff.size(); i++)
    {
        cout << diff[i];
        if((precision_diff != 0) && (i == diff.size() - precision_diff - 1))
            cout << ".";
    }
    
    vector<vector<int>> ret;
    ret.push_back(diff);
    vector<int> pres_arry = {(int)diff.size()-precision_diff-1};
    ret.push_back(pres_arry);
    cout << endl;
    return ret;
}

// limitations:
// works for usigned representation : a and b
vector<vector<int>> multiply(vector<int> a, vector<int> b, int p1, int p2, int base)
{
    //cout << "multiply 0\n";
    int k = a.size();
    int l = b.size();
    
    int precision_product = p1 + p2;
    
    int carry;
    
    //cout << "multiply 1\n";

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    vector<int> product, quo_rem;
    
    for(int i = 0; i < k + l; i++)
        product.push_back(0);
    
    for(int i = 0; i <= k - 1; i++)
    {
        carry = 0;
        //cout << "Outer loop i: " << i << endl;
        for(int j = 0; j <= l - 1; j++)
        {
            //cout << "Inner loop before QuoRem j: " << j << endl;
            quo_rem = QuoRem((a[i] * b[j]) + product[i+j] + carry, base);
            //cout << "Inner loop after QuoRem j: " << j << endl;
            carry = quo_rem[0];
            product[i+j] = quo_rem[1];
        }
        product[i+l] = carry;
    }
    
    reverse(product.begin(), product.end());
    
    product = RemovePaddingFromStart(product, precision_product);
    product = RemovePaddingFromEnd(product, &precision_product);
    
    for(int i = 0; i < product.size(); i++)
    {
        cout << product[i];
        if((precision_product != 0) && (i == product.size() - precision_product - 1))
            cout << ".";
    }

    vector<vector<int>> res;
    /*
    res.push_back(product);
    int pres_no = k + l - 1 - precision_product - abs(n - m);
    res.push_back({pres_no});

    cout << endl;
    */

    return res;
}

pair<vector<int>, int> division(vector<int> a, vector<int> b, int base, int req_pres, int p1, int p2)
{
    int k = a.size();
    int l = b.size();
    
    if(p1 > p2)
    {
        for(int idx = 1; idx <= p1 - p2; idx++)
        {
            b.push_back(0);
            l++;
        }
        //precision_diff = p1;
        
    }
    else
    {
        for(int idx = 1; idx <= p2 - p1; idx++)
        {
            a.push_back(0);
            k++;
        }
        //precision_diff = p2;
        
    }
    /*
    cout << "a: ";
    for(int idx = 0; idx < k; idx++)
        cout << a[idx] << " ";
    cout << endl << "b: ";
    for(int idx = 0; idx < l; idx++)
        cout << b[idx] << " ";
    cout << endl;
    */
    int carry;
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    //vector<int> r, q(k - l + 1, 0);
    vector<int> r, q;
    
    for(int i = 0; i <= k - 1; i++)
        r.push_back(a[i]);
    
    r.push_back(0);
    
    // Initialise q to 0 as well
    for(int i = 0; i <= k - l; i++)
        q.push_back(0);
    
    vector<int> quo_rem;
    int temp;
    
    for(int i = k - l; i >= 0; i--)
    {
        q[i] = floor(((r[i+l] * base) + r[i+l-1]) / (b[l-1] * 1.0));

        if(q[i] >= base)
            q[i] = base - 1;

        carry = 0;

        for(int j = 0; j <= l - 1; j++)
        {
            temp = r[i+j] - (q[i] * b[j]) + carry;
            quo_rem = QuoRem(temp, base);
            carry = quo_rem[0];
            r[i+j] = quo_rem[1];
        }

        r[i+l] = r[i+l] + carry;

        while(r[i+l] < 0)
        {
            carry = 0;
            
            for(int j = 0; j <= l - 1; j++)
            {
                temp = r[i+j] + b[j] + carry;
                quo_rem = QuoRem(temp, base);
                carry = quo_rem[0];
                r[i+j] = quo_rem[1];
            }

            r[i+l] = r[i+l] + carry;
            q[i] = q[i] - 1;
        }
    }

    reverse(q.begin(), q.end());
    reverse(r.begin(), r.end());
    
    int precision_division = 0;
    /*
    cout << "req_pres: " << req_pres << " div q: " << endl;
    for(int i = 0; i < q.size(); i++)
    {
        cout <<" i: " << i << " q[i]: " << q[i];
        if(i == q.size() - precision_division - 1)
            cout << ".";
    }
    cout << endl;
    
    cout << "req_pres: " << req_pres << " div r: " << endl;
    for(int i = 0; i < r.size(); i++)
    {
        cout <<" i: " << i << " r[i]: " << r[i];
    }
    cout << endl;
    */
    if(req_pres == 0)
    {
        q = RemovePaddingFromStart(q, precision_division);
        q = RemovePaddingFromEnd(q, &precision_division);
        return make_pair(q, q.size());
    }
    
    r.push_back(0);
    
    //cout << "req_pres: " << req_pres << " rem size: " << r.size() << endl;
    
    reverse(b.begin(), b.end());
    
    r = RemovePaddingFromStart(r, 0);
    //r = RemovePaddingFromEnd(r, &precision_division);
    
    pair<vector<int>, int> frac_part_res = division(r, b, base, req_pres - 1, 0, 0);
    //q.append(frac_part_res.first);
    q.insert(q.end(), frac_part_res.first.begin(), frac_part_res.first.end());
    precision_division = precision_division + frac_part_res.second;
    
    cout << "req_pres: " << req_pres << " div precision: " << precision_division << " frac part res precision: " << frac_part_res.second << endl;
    
    q = RemovePaddingFromStart(q, precision_division);
    q = RemovePaddingFromEnd(q, &precision_division);
    /*
    cout << "div q: ";
    for(int i = 0; i < q.size(); i++)
    {
        cout <<" i: " << i << " q[i]: " << q[i];
        if(i == q.size() - precision_division - 1)
            cout << ".";
    }
    cout << endl;
    */
    return make_pair(q, precision_division);
    //cout << "in quo " << q.size() << endl;;

    /*
    for(int i = 0; i < q1.size(); i++)   cout << q1[i] << " ";
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
    } //actual rem

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
    */
}



/*
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
}

vector<vector<int>> multiply(vector<int> a, vector<int> b, int n, int m, int p1, int p2, int base)
{
    cout << "multiply 0\n";
    int x = a.size();
    int y = b.size();
    int carry;
    int precision = p1 + p2;

    cout << "multiply 1\n";

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

    vector<vector<int>> res;
    res.push_back(ans);
    int pres_no = x + y - 1 - precision - abs(n - m);
    res.push_back({pres_no});

    cout << endl;

    return res;
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

vector<vector<int>> division(vector<int> a, vector<int> b, int base, int req_pres, int p1, int p2)
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
    } //actual rem

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
        cout << "half size 1 " << half[0].size() << endl;
        dv = division(a, x[0], base, 10, p, x[1][0]);
        cout << "half size" << half[0].size() << endl;
        int sz = max(x[0].size(), dv[0].size());
        ad = addition(x[0], dv[0], sz, sz, x[1][0], dv[1][0], base);
        cout << "ad: \n";
        cout << "half size" << half[0].size() << endl;
        for(int p = 0; p < half[0].size(); p++) cout << half[0][p] << " ";
        cout << endl;
        for(int p = 0; p < ad[0].size(); p++) cout << ad[0][p] << " ";
        cout << endl;
        y = multiply(half[0], ad[0], half[0].size(), ad[0].size(), half[1][0], ad[1][0], base);

        copy(y.begin(), y.end(), x.begin());
    }
    cout << "sqrt test2\n";
    cout << "root: ";
    for(int i = 0; i < y[0].size(); i++)    cout << y[0][i] << " ";
    cout << endl;
    cout << "root point: " << y[1][0] << endl;
}
*/
int main()
{
    int n, m, p1, p2, req_pres;
    cin >> n >> m >> p1 >> p2 >> req_pres;
    vector<int> a, b;
    int a_digit, b_digit;
    for(int i = 0; i < n; i++)
    {
        cin >> a_digit;
        a.push_back(a_digit);
    }
    for(int i = 0; i < m; i++)
    {
        cin >> b_digit;
        b.push_back(b_digit);
    }

    //addition(a, b, p1, p2, 10);
    //subtraction(a, b, p1, p2, 10);
    //multiply(a, b, p1, p2, 10);
    
    pair<vector<int>, int> res = division(a, b, 10, req_pres, p1, p2);
    
    cout << "main res: ";
    cout << "precision: " << res.second << endl;
    for(int i = 0; i < res.first.size(); i++)
    {
        cout << res.first[i];
        if(i == res.first.size() - res.second - 1)
            cout << ".";
    }
    
    //division(a, b, 10, 8, p1, p2);
    //square_root(a, p1, 10);
    
    cout << endl;
    return 0;
}
