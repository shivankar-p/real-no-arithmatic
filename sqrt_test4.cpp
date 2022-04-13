#include<bits/stdc++.h>
#define int long long

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
    //cout << "scale: " << scale << endl;
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
pair<vector<int>, int> addition(vector<int> a, vector<int> b, int p1, int p2, int base)
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
    /*
    cout << "a: ";
    for(int idx = 0; idx < k; idx++)
        cout << a[idx] << " ";
    cout << endl << "b: ";
    for(int idx = 0; idx < l; idx++)
        cout << b[idx] << " ";
    cout << endl;
    */
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
    /*
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
    */
    /*
    vector<vector<int>> ret;
    ret.push_back(sum);
    vector<int> pres_arry = {(int)sum.size()-precision_sum-1};
    ret.push_back(pres_arry);
    cout << endl;
    */
    
    return make_pair(sum, precision_sum);
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
    /*
    cout << "a: ";
    for(int idx = 0; idx < k; idx++)
        cout << a[idx] << " ";
    cout << endl << "b: ";
    for(int idx = 0; idx < l; idx++)
        cout << b[idx] << " ";
    cout << endl;
    */
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
    /*
    for(i = 0; i < diff.size(); i++)
    {
        cout << diff[i];
        if((precision_diff != 0) && (i == diff.size() - precision_diff - 1))
            cout << ".";
    }
    */
    vector<vector<int>> ret;
    ret.push_back(diff);
    vector<int> pres_arry = {(int)diff.size()-precision_diff-1};
    ret.push_back(pres_arry);
    cout << endl;
    return ret;
}

// limitations:
// works for usigned representation : a and b
pair<vector<int>, int> multiply(vector<int> a, vector<int> b, int p1, int p2, int base)
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
    /*
    for(int i = 0; i < product.size(); i++)
    {
        cout << product[i];
        if((precision_product != 0) && (i == product.size() - precision_product - 1))
            cout << ".";
    }
    *?
    //vector<vector<int>> res;
    /*
    res.push_back(product);
    int pres_no = k + l - 1 - precision_product - abs(n - m);
    res.push_back({pres_no});

    cout << endl;
    */

    return make_pair(product, precision_product);
}

pair<vector<int>, vector<int>> division_int(vector<int> a, vector<int> b, int base)
{
    int k = a.size();
    int l = b.size();
    
    if(k < l)
    {
        vector<int> quo, rem;
        /*
        while(a[a.size() - 1] == 0)
        {
            a.pop_back();
            quo.push_back(0);
        }
        */
        
        quo.push_back(0);
        rem = a;
        
        return make_pair(quo, rem);
    }
    
    int carry;
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

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
    
    q = RemovePaddingFromStart(q, precision_division);
    //q = RemovePaddingFromEnd(q, &precision_division);
    
    r = RemovePaddingFromStart(r, precision_division);
    //r = RemovePaddingFromEnd(r, &precision_division);
    
    return make_pair(q, r);
}


pair<vector<int>, int> division(vector<int> a, vector<int> b, int base, int req_pres, int p1, int p2)
{
    a = RemovePaddingFromStart(a, p1);
    a = RemovePaddingFromEnd(a, &p1);

    b = RemovePaddingFromStart(b, p2);
    b = RemovePaddingFromEnd(b, &p2);

    int k = a.size();
    int l = b.size();
    
    if(p1 > p2)
    {
        for(int idx = 1; idx <= p1 - p2; idx++)
        {
            b.push_back(0);
            l++;
        }
        
    }
    else
    {
        for(int idx = 1; idx <= p2 - p1; idx++)
        {
            a.push_back(0);
            k++;
        }
        
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
    
     if(k < l)
         q.push_back(0);
    
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
    
    int precision_division = 0;
    
    reverse(r.begin(), r.end());
    /*
    cout << "Before adding padding div r: " << endl;
    for(int i = 0; i < r.size(); i++)
    {
        cout <<" i: " << i << " r[i]: " << r[i];
    }
    cout << endl;
    */
    for(int idx = 0; idx < req_pres; idx++)
        r.push_back(0);
    /*
    cout << "Before removing padding div r: " << endl;
    for(int i = 0; i < r.size(); i++)
    {
        cout <<" i: " << i << " r[i]: " << r[i];
    }
    cout << endl;
    */
    r = RemovePaddingFromStart(r, 0);
    //r = RemovePaddingFromEnd(r, &precision_division); Not to be done?
    /*
    cout << "After removing padding div r: " << endl;
    for(int i = 0; i < r.size(); i++)
    {
        cout <<" i: " << i << " r[i]: " << r[i];
    }
    cout << endl;
    */
    reverse(b.begin(), b.end());
    
    pair<vector<int>, vector<int>> frac_part_res = division_int(r, b, 10);
    /*
    cout << "Frac part res returned quo: " << endl;
    for(int i = 0; i < frac_part_res.first.size(); i++)
    {
        cout <<" i: " << i << " frac_part_res.first[i]: " << frac_part_res.first[i];
    }
    cout << endl;
    
    cout << "Before insert frac part res div q: " << endl;
    for(int i = 0; i < q.size(); i++)
    {
        cout <<" i: " << i << " q[i]: " << q[i];
        if(i == q.size() - precision_division - 1)
            cout << ".";
    }
    cout << endl;
    */
    int num_zeros = req_pres - frac_part_res.first.size();
    while(num_zeros > 0)
    {
        q.push_back(0);
        precision_division = precision_division + 1;
        num_zeros = num_zeros - 1;
    }
    
    q.insert(q.end(), frac_part_res.first.begin(), frac_part_res.first.end());
    /*
    cout << "After insert frac part res div q: " << endl;
    for(int i = 0; i < q.size(); i++)
    {
        cout <<" i: " << i << " q[i]: " << q[i];
        if(i == q.size() - precision_division - 1)
            cout << ".";
    }
    cout << endl;
    */
    precision_division = precision_division + frac_part_res.first.size();
    /*
    cout << "Before remove padding of div q, precision_division: " << precision_division << endl;
    
    cout << "Before remove padding div q: " << endl;
    for(int i = 0; i < q.size(); i++)
    {
        cout <<" i: " << i << " q[i]: " << q[i];
        if(i == q.size() - precision_division - 1)
            cout << ".";
    }
    cout << endl;
    */
    q = RemovePaddingFromStart(q, precision_division);
    q = RemovePaddingFromEnd(q, &precision_division);
    /*
    cout << "After remove padding div q: " << endl;
    for(int i = 0; i < q.size(); i++)
    {
        cout <<" i: " << i << " q[i]: " << q[i];
        if(i == q.size() - precision_division - 1)
            cout << ".";
    }
    cout << endl;
    */
    return make_pair(q, precision_division);
    
}


pair<vector<int>, int> square_root(vector<int> R, int p, int base, int total_precision)
{
    pair<vector<int>, int> x;
    
    x.first = R;
    x.second = p;
    
    pair<vector<int>, int> dv, ad, y;
    
    pair<vector<int>, int> half;
    half.first = {0, 5};
    half.second = 1;

    cout << "chk 0\n";
    
    //cout << "sqrt test1\n";
    for(int i = 0; i < 100; i++)
    {
        cout << "first num " << total_precision << endl;
        cout << R.size() << endl;

        for(int p = 0; p < R.size(); p++)   cout << R[p] << " ";
        cout << endl;

        cout << "p1 :" << p <<  endl;

        cout << "sec num\n";
        cout << x.first.size() << endl;

        for(int p = 0; p < x.first.size(); p++)   cout << x.first[p] << " ";
        cout << endl;

        cout << "p2 :" << x.second <<  endl;

        dv = division(R, x.first, base, total_precision, p, x.second);

        



        cout << "div: " << i << " line: 1" << endl;
        
        ad = addition(x.first, dv.first, x.second, dv.second, base);

        cout << "div: " << i << " line: 2" << endl;
        
        y = multiply(half.first, ad.first, half.second, ad.second, base);

        cout << "div: " << i << " line: 3" << endl;
        
        x.first = y.first;
        
        x.second = y.second;
    }
    
    return x;
    
}

void pi(int total_precision, int base)
{
    pair<vector<int>, int> a, b, p, sq_an, inv, sum;
    
    vector<int> two = {2};
    vector<int> one = {1};
    vector<int> zero = {0};
    
    a = square_root(two, 0, base, total_precision);
    
    b.first = zero;
    b.second = 0;
    
    p = addition(a.first, two, a.second, 0, base);
    
    
    pair<vector<int>, int> a_next, b_next, p_next;
    
    pair<vector<int>, int> half;
    half.first = {0, 5};
    half.second = 1;
    
    //cout << "sqrt test1\n";
    for(int i = 0; i < 100; i++)
    {
        // 1st line
        cout << "start\n";
        sq_an = square_root(a.first, a.second, base, total_precision);
        cout << "a\n";
        inv = division(one, sq_an.first, base, total_precision, 0, sq_an.second);
        cout << "b\n";
        a_next = addition(sq_an.first, inv.first, sq_an.second, inv.second, base);
        cout << "c\n";
        a_next = division(a_next.first, two, base, total_precision, a_next.second, 0);

        cout << "pi: " << i << " line: 1" << endl;
        
        // 2nd line
        sum = addition(a.first, b.first, a.second, b.second, base);
        b_next = addition(one, b.first, 0, b.second, base);
        b_next = multiply(b_next.first, sq_an.first, b_next.second, sq_an.second, base);
        b_next = division(b_next.first, sum.first, base, total_precision, b_next.second, sum.second);

        cout << "pi: " << i << " line: 2" << endl;
        
        // 3rd line
        sum = addition(one, b_next.first, 0, b_next.second, base);
        p_next = addition(one, a_next.first, 0, a_next.second, base);
        p_next = multiply(p_next.first, p.first, p_next.second, p.second, base);
        p_next = multiply(p_next.first, b_next.first, p_next.second, b_next.second, base);
        p_next = division(p_next.first, sum.first, base, total_precision, p_next.second, sum.second);
        
        a = a_next;
        
        b = b_next;
        
        p = p_next;
        
        cout << "pi: " << i << " line: 3" << endl;
        
    }
    //cout << "sqrt test2\n";
    //cout << "root: ";
    
    //x.first.resize(total_precision, 0);
    
    
    
    for(int i = 0; i < p.first.size(); i++)
    {
        cout << p.first[i];
        if(i == p.first.size() - p.second - 1)
            cout << ".";
    }
    return;
}


int32_t main()
{
    int total_precision, base;
    cin >> total_precision >> base;
    
    pi(total_precision, base);
    return 0;
}
