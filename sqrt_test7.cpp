#include<bits/stdc++.h>

using namespace std;

vector<int> RemovePaddingFromStart(vector<int> num, int precision_num)
{
    int scale_num = num.size() - precision_num;
    //cout << "scale: " << scale << endl;
    
    vector<int>::iterator it = num.begin();
    while((*it == 0) && (scale_num !=  1))
    {
        vector<int>::iterator cur = it;
        it = num.erase(cur);
        scale_num = scale_num - 1;
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

// returns true if num1 is smaller than num2
bool isSmallerThan(pair<vector<int>, int> num1, pair<vector<int>, int> num2)
{
    int scale_num1 = num1.first.size() - num1.second;
    int scale_num2 = num2.first.size() - num2.second;
    
    cout << "num1 precision: " << num1.second << endl;
    cout << "num2 precision: " << num2.second << endl;
    
    cout << "num1 before comparison padding: ";
    for(int idx = 0; idx < num1.first.size(); idx++)
        cout << num1.first[idx] << " ";
    cout << endl << "num2 before comparison padding: ";
    for(int idx = 0; idx < num2.first.size(); idx++)
        cout << num2.first[idx] << " ";
    cout << endl;
    
    if(scale_num1 > scale_num2)
    {
        num2.first.insert(num2.first.begin(), scale_num1 - scale_num2, 0);
        scale_num2 = scale_num2 + (scale_num1 - scale_num2);
        // scale_num2 = scale_num1;
    }
    else
    {
        num1.first.insert(num1.first.begin(), scale_num2 - scale_num1, 0);
        scale_num1 = scale_num1 + (scale_num2 - scale_num1);
        // scale_num1 = scale_num2;
    }
    
    if(num1.second > num2.second)
    {
        num2.first.insert(num2.first.end(), num1.second - num2.second, 0);
        num2.second = num2.second + (num1.second - num2.second);
        // num2.second = num1.second;
    }
    else
    {
        num1.first.insert(num1.first.end(), num2.second - num1.second, 0);
        num1.second = num1.second + (num2.second - num1.second);
        // num1.second = num2.second;
    }
    
    cout << "num1 after comparison padding: ";
    for(int idx = 0; idx < num1.first.size(); idx++)
        cout << num1.first[idx] << " ";
    cout << endl << "num2 after comparison padding: ";
    for(int idx = 0; idx < num2.first.size(); idx++)
        cout << num2.first[idx] << " ";
    cout << endl;
    
    bool ret = true;
    
    for(int idx = 0; idx < num1.first.size(); idx++)
    {
        if(num1.first[idx] > num2.first[idx])
            return false;
    }
    
    ret = !(equal(num1.first.begin(), num1.first.end(), num2.first.begin()));
    
    cout << "ret: " << ret << endl;
    
    return ret;
}
/*
pair<vector<int>, int> convertToBase10(pair<vector<int>, int> num, int base, int total_precision)
{
    int scale = num.first.size() - num.second;
    int precision = num.second;
    
    int pow = 1;
    
    while((scale >= 0) && (precision >= 0))
    {
        
    }
    for(int idx = 0; idx < num.first.size(); idx++)
    {
        num.first[idx] =
    }
}
*/
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
pair<vector<int>, int> addition(vector<int> a, vector<int> b, int p1, int p2, int base, int total_precision)
{
    a = RemovePaddingFromStart(a, p1);
    b = RemovePaddingFromStart(b, p2);
    
    a = RemovePaddingFromEnd(a, &p1);
    b = RemovePaddingFromEnd(b, &p2);
    
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
    
    sum = RemovePaddingFromStart(sum, precision_sum);
    sum = RemovePaddingFromEnd(sum, &precision_sum);
    
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
    
    precision_sum = total_precision + 1 - sum.size() + precision_sum;
    /*
    if((sum.size() > total_precision + 1) && (sum[total_precision + 1] > 5))
        sum[total_precision] = sum[total_precision] + 1;
    else if((sum.size() >= total_precision + 1) && (sum[total_precision + 1] == 5))
        if(sum[total_precision] % 2 == 1)
            sum[total_precision] = sum[total_precision] + 1;
    */
    sum.resize(total_precision + 1, 0);
    
    return make_pair(sum, precision_sum);
}

// limitations:
// works for usigned representation : a and b
// works for a >= b i.e. returns correct if a - b >= 0 and hence doesn't work for ((a.size() < b.size()) || ((a.size() == b.size()) && (a[0] < b[0])))
pair<vector<int>, int> subtraction(vector<int> a, vector<int> b, int p1, int p2, int base, int total_precision)
{
    a = RemovePaddingFromStart(a, p1);
    b = RemovePaddingFromStart(b, p2);
    
    a = RemovePaddingFromEnd(a, &p1);
    b = RemovePaddingFromEnd(b, &p2);
    
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
    
    cout << "a precision: " << p1 << endl;
    cout << "b precision: " << p2 << endl;
    
    cout << "a in sub: ";
    for(int idx = 0; idx < k; idx++)
        cout << a[idx] << " ";
    cout << endl << "b in sub: ";
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
    
    //diff.push_back(carry);
    
    reverse(diff.begin(), diff.end());
    
    cout << "diff in sub after subtraction: " << endl;
    for(int j = 0; j < diff.size(); j++)
    {
        cout << diff[j];
        if(j == diff.size() - precision_diff - 1)
            cout << ".";
    }
    cout << endl;
    
    diff = RemovePaddingFromStart(diff, precision_diff);
    diff = RemovePaddingFromEnd(diff, &precision_diff);
    /*
    for(i = 0; i < diff.size(); i++)
    {
        cout << diff[i];
        if((precision_diff != 0) && (i == diff.size() - precision_diff - 1))
            cout << ".";
    }
    */
    /*
    vector<vector<int>> ret;
    ret.push_back(diff);
    vector<int> pres_arry = {(int)diff.size()-precision_diff-1};
    ret.push_back(pres_arry);
    cout << endl;
    return ret;
    */
    
    precision_diff = total_precision + 1 - diff.size() + precision_diff;
    /*
    if((diff.size() > total_precision + 1) && (diff[total_precision + 1] > 5))
        diff[total_precision] = diff[total_precision] + 1;
    else if((diff.size() >= total_precision + 1) && (diff[total_precision + 1] == 5))
        if(diff[total_precision] % 2 == 1)
            diff[total_precision] = diff[total_precision] + 1;
    */
    diff.resize(total_precision + 1, 0);
    
    return make_pair(diff, precision_diff);
}

// limitations:
// works for usigned representation : a and b
pair<vector<int>, int> multiply(vector<int> a, vector<int> b, int p1, int p2, int base, int total_precision)
{
    a = RemovePaddingFromStart(a, p1);
    b = RemovePaddingFromStart(b, p2);
    
    a = RemovePaddingFromEnd(a, &p1);
    b = RemovePaddingFromEnd(b, &p2);
    
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
    
    precision_product = total_precision + 1 - product.size() + precision_product;
    /*
    if((product.size() > total_precision + 1) && (product[total_precision + 1] > 5))
        product[total_precision] = product[total_precision] + 1;
    else if((product.size() >= total_precision + 1) && (product[total_precision + 1] == 5))
        if(product[total_precision] % 2 == 1)
            product[total_precision] = product[total_precision] + 1;
    */
    product.resize(total_precision + 1, 0);

    return make_pair(product, precision_product);
}

pair<vector<int>, vector<int>> division_int(vector<int> a, vector<int> b, int base)
{
    a = RemovePaddingFromStart(a, 0);
    b = RemovePaddingFromStart(b, 0);
    
    //a = RemovePaddingFromEnd(a, &p1);
    //b = RemovePaddingFromEnd(b, &p2);
    
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
    b = RemovePaddingFromStart(b, p2);
    
    a = RemovePaddingFromEnd(a, &p1);
    b = RemovePaddingFromEnd(b, &p2);
    
    for(int idx = 0; idx < b.size(); idx++)
    {
        if(b[idx] != 0)
            break;
        a.push_back(0);
        if(p1 > 0)
            p1--;
        b.push_back(0);
        if(p2 > 0)
            p2--;
    }
    
    a = RemovePaddingFromStart(a, p1);
    b = RemovePaddingFromStart(b, p2);
    
    //a = RemovePaddingFromEnd(a, &p1);
    //b = RemovePaddingFromEnd(b, &p2);
    
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
    
    pair<vector<int>, vector<int>> frac_part_res = division_int(r, b, base);
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
    precision_division = req_pres + 1 - q.size() + precision_division;
    /*
    if((q.size() > req_pres + 1) && (q[req_pres + 1] > 5))
        q[req_pres] = q[req_pres] + 1;
    else if((q.size() >= req_pres + 1) && (q[req_pres + 1] == 5))
        if(q[req_pres] % 2 == 1)
            q[req_pres] = q[req_pres] + 1;
    */
    q.resize(req_pres + 1, 0);
    
    return make_pair(q, precision_division);
    
}


pair<vector<int>, int> square_root(vector<int> R, int p, int base, int total_precision)
{
    //total_precision = required precision
    pair<vector<int>, int> x;
    
    x.first = R;
    x.second = p;
    
    pair<vector<int>, int> dv, ad, y, diff, req_diff;
    
    req_diff.first.push_back(0);
    req_diff.second = 0;
    
    for(int idx = 1; idx <= total_precision - 1; idx++)
    {
        req_diff.first.push_back(0);
        req_diff.second++;
    }
    
    req_diff.first.push_back(1);
    req_diff.second++;
    
    pair<vector<int>, int> half;
    half.first = {0, base/2};
    half.second = 1;
    
    //int i = 1;
    //cout << "sqrt test1\n";
    for(int i = 0; i < 30; i++)
    //while(1)
    {
        //cout << "half size 1 " << half[0].size() << endl;
        dv = division(R, x.first, base, total_precision, p, x.second);
        //cout << "After div i: " << i << endl;
        //cout << "half size" << half[0].size() << endl;
        //int sz = max(x[0].size(), dv[0].size());
        ad = addition(x.first, dv.first, x.second, dv.second, base, total_precision);
        //cout << "After add i: " << i << endl;
        //cout << "ad: \n";
        //cout << "half size" << half[0].size() << endl;
        /*
        for(int p = 0; p < half[0].size(); p++) cout << half[0][p] << " ";
        cout << endl;
        for(int p = 0; p < ad[0].size(); p++) cout << ad[0][p] << " ";
        cout << endl;
        */
        y = multiply(half.first, ad.first, half.second, ad.second, base, total_precision);
        //cout << "After mul i: " << i << endl;
        
        //diff = subtraction(x.first, y.first, x.second, y.second, base, total_precision);
        
        //diff.second = total_precision + 1 - diff.first.size() + diff.second;
        /*
        if((diff.first.size() > total_precision + 1) && (diff.first[total_precision + 1] > 5))
            diff.first[total_precision] = diff.first[total_precision] + 1;
        else if((diff.first.size() >= total_precision + 1) && (diff.first[total_precision + 1] == 5))
            if(diff.first[total_precision] % 2 == 1)
                diff.first[total_precision] = diff.first[total_precision] + 1;
        */
        //diff.first.resize(total_precision + 1, 0);
        
        //cout << "i before compare: " << i << endl;
        
        //if(isSmallerThan(diff, req_diff))
        //    break;
        
        //cout << "i after compare: " << i << endl;
        //i++;
        
        //copy(y.first.begin(), y.first.end(), x.first.begin());
        x.first = y.first;
        //cout << "After copy i: " << i << endl;
        x.second = y.second;
    }
    //cout << "sqrt test2\n";
    //cout << "root: ";
    
    y.second = total_precision + 1 - y.first.size() + y.second;
    /*
    if((y.first.size() > total_precision + 1) && (y.first[total_precision + 1] > 5))
        y.first[total_precision] = y.first[total_precision] + 1;
    else if((y.first.size() >= total_precision + 1) && (y.first[total_precision + 1] == 5))
        if(y.first[total_precision] % 2 == 1)
            y.first[total_precision] = y.first[total_precision] + 1;
    */
    y.first.resize(total_precision + 1, 0);
    
    cout << "square root: ";
    for(int i = 0; i < y.first.size(); i++)
    {
        cout << y.first[i];
        if(i == y.first.size() - y.second - 1)
            cout << ".";
    }
    cout << endl;
    
    
    return y;
    /*
    for(int i = 0; i < x.first.size(); i++)
    {
        cout << x.first[i];
        if(i == x.first.size() - x.second - 1)
            cout << ".";
    }
    cout << endl;
    */
    //cout << "root point: " << y[1][0] << endl;
    //x.first.clear();
    //y.first.clear();
}

void change_base(pair<vector<int>, int> arr, int start_pres, int base)
{
    pair<vector<int>,int> n = {{0}, 0};
    pair<vector<int>,int> x;
    pair<vector<int>, int> base_v;
    base_v.second = 0;
    int tmp = base;
    int r;
    while(tmp > 0)
    {
        r = tmp%10;
        base_v.first.push_back(r);
        tmp /= 10;
    }

    reverse(base_v.first.begin(), base_v.first.end());

    int i;
    for(i = 0; i <= start_pres; i++)
    {
        x = multiply(base_v.first, n.first, base_v.second, n.second, 10, 10);

        n = addition(x.first, {arr.first[i]}, x.second, 0, 10, 10);

        cout << "changed base\n";
        for(int i = 0; i < n.first.size(); i++)
        {
            cout << n.first[i] << " ";
        }
        cout << endl;
        cout << n.second << endl;
    }

    cout << "next loop" << endl;

    int pwr = 1;
    int plc = pow(base, pwr);
    pair<vector<int>, int> plc_v;
    plc_v.second = 0;

    plc = pow(base, pwr);
    plc_v.first.clear();
    while(plc>0)
    {
        plc_v.first.push_back(plc%10);
        plc /= 10;
    }
    reverse(plc_v.first.begin(), plc_v.first.end());

    for(; i < arr.first.size(); i++)
    {

        vector<int> dig_break;
        int tpr = arr.first[i];
        while(tpr > 0)
        {
            dig_break.push_back(tpr%10);
            tpr /= 10;
        }
        reverse(dig_break.begin(), dig_break.end());
        
        x = division(dig_break, plc_v.first, 10, 10, 0, 0);
        for(int p = 0; p < 10; p++) cout << x.first[p] << " ";
        cout << endl;
        cout << x.second << endl;
        n = addition(n.first, x.first, n.second, n.second, 10, 10);

        plc_v = multiply(plc_v.first, base_v.first, 0, 0, 10, 10);

        

        cout << "changed base\n";
        for(int i = 0; i < n.first.size(); i++)
        {
            cout << n.first[i] << " ";
        }
        cout << endl;
        cout << n.second << endl;
    }
}

void pi(int total_precision, int base)
{
    pair<vector<int>, int> a, b, p, sq_an, inv, sum;
    
    vector<int> two = {2};
    vector<int> one = {1};
    vector<int> zero = {0};
    
    pair<vector<int>, int> diff, req_diff;
    
    req_diff.first.push_back(0);
    req_diff.second = 0;
    
    for(int idx = 1; idx <= total_precision - 1; idx++)
    {
        req_diff.first.push_back(0);
        req_diff.second++;
    }
    
    req_diff.first.push_back(1);
    req_diff.second++;
    
    int total_precison_with_guard_digits = ceil(total_precision + log(total_precision + 8));
    //int total_precison_with_guard_digits = total_precision + 2;
    a = square_root(two, 0, base, total_precison_with_guard_digits);
    
    cout << "a_init: " << endl;
    for(int j = 0; j < total_precision; j++)
    {
        cout << a.first[j];
        if(j == a.first.size() - a.second - 1)
            cout << ".";
    }
    cout << endl;
    
    b.first = zero;
    b.second = 0;
    
    p = addition(a.first, two, a.second, 0, base, total_precison_with_guard_digits);
    
    
    pair<vector<int>, int> a_next, b_next, p_next;
    
    pair<vector<int>, int> half;
    half.first = {0, base/2};
    half.second = 1;
    
    int i = 1;
    //cout << "sqrt test1\n";
    for(int i = 0; i < 4; i++)
    //while(1)
    {
        cout << "i: " << i << endl;
        
        // 1st line
        sq_an = square_root(a.first, a.second, base, total_precison_with_guard_digits);
        
        cout << "sq_an: " << endl;
        for(int j = 0; j < sq_an.first.size(); j++)
        {
            cout << sq_an.first[j];
            if(j == sq_an.first.size() - sq_an.second - 1)
                cout << ".";
        }
        cout << endl;
        
        inv = division(one, sq_an.first, base, total_precison_with_guard_digits, 0, sq_an.second);
        a_next = addition(sq_an.first, inv.first, sq_an.second, inv.second, base, total_precison_with_guard_digits);
        
        cout << "a_next before div: " << endl;
        for(int j = 0; j < a_next.first.size(); j++)
        {
            cout << a_next.first[j];
            if(j == a_next.first.size() - a_next.second - 1)
                cout << ".";
        }
        cout << endl;
        
        a_next = division(a_next.first, two, base, total_precison_with_guard_digits, a_next.second, 0);
        
        cout << "sq_an: " << endl;
        for(int j = 0; j < sq_an.first.size(); j++)
        {
            cout << sq_an.first[j];
            if(j == sq_an.first.size() - sq_an.second - 1)
                cout << ".";
        }
        cout << endl;
        cout << "inv: " << endl;
        for(int j = 0; j < inv.first.size(); j++)
        {
            cout << inv.first[j];
            if(j == inv.first.size() - inv.second - 1)
                cout << ".";
        }
        cout << endl;
        cout << "a_next after div: " << endl;
        for(int j = 0; j < a_next.first.size(); j++)
        {
            cout << a_next.first[j];
            if(j == a_next.first.size() - a_next.second - 1)
                cout << ".";
        }
        cout << endl;
        
        // 2nd line
        sum = addition(a.first, b.first, a.second, b.second, base, total_precison_with_guard_digits);
        b_next = addition(one, b.first, 0, b.second, base, total_precison_with_guard_digits);
        b_next = multiply(b_next.first, sq_an.first, b_next.second, sq_an.second, base, total_precison_with_guard_digits);
        b_next = division(b_next.first, sum.first, base, total_precison_with_guard_digits, b_next.second, sum.second);
        
        // 3rd line
        sum = addition(one, b_next.first, 0, b_next.second, base, total_precison_with_guard_digits);
        p_next = addition(one, a_next.first, 0, a_next.second, base, total_precison_with_guard_digits);
        p_next = multiply(p_next.first, p.first, p_next.second, p.second, base, total_precison_with_guard_digits);
        p_next = multiply(p_next.first, b_next.first, p_next.second, b_next.second, base, total_precison_with_guard_digits);
        
        cout << "p_next before div: " << endl;
        for(int j = 0; j < p_next.first.size(); j++)
        {
            cout << p_next.first[j];
            if(j == p_next.first.size() - p_next.second - 1)
                cout << ".";
        }
        cout << endl;
        
        p_next = division(p_next.first, sum.first, base, total_precison_with_guard_digits, p_next.second, sum.second);
        
        cout << "p_next after div: " << endl;
        for(int j = 0; j < p_next.first.size(); j++)
        {
            cout << p_next.first[j];
            if(j == p_next.first.size() - p_next.second - 1)
                cout << ".";
        }
        cout << endl;
        
        //diff = subtraction(p_next.first, p.first, p_next.second, p.second, base, total_precison_with_guard_digits);
        /*
        cout << "diff after subtraction: " << endl;
        for(int j = 0; j < diff.first.size(); j++)
        {
            cout << diff.first[j];
            if(j == diff.first.size() - diff.second - 1)
                cout << ".";
        }
        cout << endl;
        */
        //diff.second = total_precision + 1 - diff.first.size() + diff.second;
        
        //diff.first.resize(total_precision + 1, 0);
        
        cout << "i before compare: " << i << endl;
        
        //if((i > 1 ) && (isSmallerThan(diff, req_diff)))
        //if(isSmallerThan(diff, req_diff))
        //    break;
        
        cout << "i after compare: " << i << endl;
        
        
        a = a_next;
        
        b = b_next;
        
        p = p_next;
        
        
        cout << "a: " << endl;
        for(int j = 0; j < a.first.size(); j++)
        {
            cout << a.first[j];
            if(j == a.first.size() - a.second - 1)
                cout << ".";
        }
        cout << endl;
        cout << "b: " << endl;
        for(int j = 0; j < b.first.size(); j++)
        {
            cout << b.first[j];
            if(j == b.first.size() - b.second - 1)
                cout << ".";
        }
        cout << endl;
        cout << "p: " << endl;
        for(int j = 0; j < p.first.size(); j++)
        {
            cout << p.first[j];
            if(j == p.first.size() - p.second - 1)
                cout << ".";
        }
        cout << endl;
        for(int j = 0; j < p.first.size(); j++)
        {
            cout << p.first[j];
            if(j == p.first.size() - p.second - 1)
                cout << ".";
        }
        cout << endl;
        
        i++;
        
    }
    //cout << "sqrt test2\n";
    //cout << "root: ";
    
    //x.first.resize(total_precision, 0);
    
    
    
    for(int i = 0; i < total_precision + 1; i++)
    {
        cout << p_next.first[i] << " ";
        if(i == p_next.first.size() - p_next.second - 1)
            cout << "." << " ";
    }
    cout << endl;
    change_base(p_next, p_next.first.size() - p_next.second, base);
    return;
    //cout << endl;
    //cout << "root point: " << y[1][0] << endl;
    //x.first.clear();
    //y.first.clear();
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
    int total_precision, base;
    
    cin >> total_precision >> base;
    
    //int n, p;
    //cin >> n >> p;
    /*
    vector<int> a;
    int a_digit, b_digit;
    for(int i = 0; i < n; i++)
    {
        cin >> a_digit;
        a.push_back(a_digit);
    }
    */
    /*
    for(int i = 0; i < m; i++)
    {
        cin >> b_digit;
        b.push_back(b_digit);
    }
    */
    //addition(a, b, p1, p2, 10);
    //subtraction(a, b, p1, p2, 10);
    //multiply(a, b, p1, p2, 10);
    
    //pair<vector<int>, vector<int>> res = division_int(a, b, 10);
    
    /*
    cout << "quotient: " << endl;
    for(int i = 0; i < res.first.size(); i++)
    {
        //cout << " i: " << i << " quo[i]: "<< res.first[i];
        cout << res.first[i];
    }
    cout << endl;
    cout << "remainder: " << endl;
    for(int i = 0; i < res.second.size(); i++)
    {
        //cout << " i: " << i << " quo[i]: "<< res.first[i];
        cout << res.second[i];
    }
    cout << endl;
    */
    
    //pair<vector<int>, int> res = division(a, b, 10, req_pres, p1, p2);
    //square_root(a, p, 10, total_precision);
    /*
    cout << "quotient: " << endl;
    for(int i = 0; i < res.first.size(); i++)
    {
        //cout << " i: " << i << " quo[i]: "<< res.first[i];
        cout << res.first[i];
        if(i == res.first.size() - res.second - 1)
            cout << ".";
    }
    cout << endl;
    */
    //pi(total_precision, base);
    pair<vector<int>, int> pr;
    pr.first = {3, 36, 63, 106, 136, 133};
    pr.second = 5;
    change_base(pr, 0, 256);
    return 0;
}
