// Aniruddha Chaudhari IMT2020025
// Shivankar Pilligundla IMT2020016

#include<bits/stdc++.h>

using namespace std;

pair<vector<int>, int> RemovePaddingFromStart(pair<vector<int>, int> num)
{
    if(num.first.size() == 0)
        return num;
    
    int scale_num = num.first.size() - num.second;
    
    vector<int>::iterator it = num.first.begin();
    while((*it == 0) && (scale_num !=  1))
    {
        vector<int>::iterator cur = it;
        it = num.first.erase(cur);
        scale_num = scale_num - 1;
    }
    
    return num;
}

pair<vector<int>, int> RemovePaddingFromEnd(pair<vector<int>, int> num)
{
    if(num.first.size() == 0)
        return num;
    
    while((num.first[num.first.size() - 1] == 0) && (num.second != 0))
    {
        num.first.pop_back();
        num.second = num.second - 1;
    }
    
    return num;
}

bool isSmallerThan(pair<vector<int>, int> num1, pair<vector<int>, int> num2)
{
    int scale_num1 = num1.first.size() - num1.second;
    int scale_num2 = num2.first.size() - num2.second;
    
    if(scale_num1 > scale_num2)
    {
        num2.first.insert(num2.first.begin(), scale_num1 - scale_num2, 0);
        scale_num2 = scale_num2 + (scale_num1 - scale_num2);
    }
    else
    {
        num1.first.insert(num1.first.begin(), scale_num2 - scale_num1, 0);
        scale_num1 = scale_num1 + (scale_num2 - scale_num1);
    }
    
    if(num1.second > num2.second)
    {
        num2.first.insert(num2.first.end(), num1.second - num2.second, 0);
        num2.second = num2.second + (num1.second - num2.second);
    }
    else
    {
        num1.first.insert(num1.first.end(), num2.second - num1.second, 0);
        num1.second = num1.second + (num2.second - num1.second);
    }
    
    bool ret = true;
    
    for(int idx = 0; idx < num1.first.size(); idx++)
    {
        if(num1.first[idx] > num2.first[idx])
            return false;
    }
    
    return ret;
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

pair<vector<int>, int> addition(pair<vector<int>, int> num1, pair<vector<int>, int> num2, int base, int required_precision)
{
    num1 = RemovePaddingFromStart(num1);
    num2 = RemovePaddingFromStart(num2);
    
    num1 = RemovePaddingFromEnd(num1);
    num2 = RemovePaddingFromEnd(num2);
    
    int k = num1.first.size();
    int l = num2.first.size();
    
    pair<vector<int>, int> sum;
    
    sum.second;
    
    if(num1.second > num2.second)
    {
        for(int idx = 1; idx <= num1.second - num2.second; idx++)
        {
            num2.first.push_back(0);
            l++;
        }
        sum.second = num1.second;
        
    }
    else
    {
        for(int idx = 1; idx <= num2.second - num1.second; idx++)
        {
            num1.first.push_back(0);
            k++;
        }
        sum.second = num2.second;
        
    }
    
    int carry = 0;
    
    int i = k - 1;
    int j = l - 1;
    
    vector<int> quo_rem;
    
    while(i >= 0 && j >= 0)
    {
        quo_rem = QuoRem(num1.first[i] + num2.first[j] + carry, base);
        
        carry = quo_rem[0];
        sum.first.push_back(quo_rem[1]);
        
        i--;
        j--;
    }

    while(i >= 0)
    {
        quo_rem = QuoRem(num1.first[i] + carry, base);
        
        carry = quo_rem[0];
        sum.first.push_back(quo_rem[1]);
        
        i--;
    }

    while(j >= 0)
    {
        quo_rem = QuoRem(num2.first[j] + carry, base);
        
        carry = quo_rem[0];
        sum.first.push_back(quo_rem[1]);
        
        j--;
    }

    if(carry > 0)
         sum.first.push_back(carry);
    
    reverse(sum.first.begin(), sum.first.end());
    
    sum = RemovePaddingFromStart(sum);
    sum = RemovePaddingFromEnd(sum);
    
    sum.first.resize(required_precision + sum.first.size() - sum.second, 0);
    sum.second = required_precision;
    
    return sum;
}

pair<vector<int>, int> subtraction(pair<vector<int>, int> num1, pair<vector<int>, int> num2, int base, int required_precision)
{
    num1 = RemovePaddingFromStart(num1);
    num2 = RemovePaddingFromStart(num2);
    
    num1 = RemovePaddingFromEnd(num1);
    num2 = RemovePaddingFromEnd(num2);
    
    int k = num1.first.size();
    int l = num2.first.size();
    
    pair<vector<int>, int> difference;
    
    if(num1.second > num2.second)
    {
        for(int idx = 1; idx <= num1.second - num2.second; idx++)
        {
            num2.first.push_back(0);
            l++;
        }
        difference.second = num1.second;
        
    }
    else
    {
        for(int idx = 1; idx <= num2.second - num1.second; idx++)
        {
            num1.first.push_back(0);
            k++;
        }
        difference.second = num2.second;
        
    }
    
    int carry = 0;
    
    int i = k - 1;
    int j = l - 1;
    
    vector<int> quo_rem;
    
    while(i >= 0 && j >= 0)
    {
        quo_rem = QuoRem(num1.first[i] - num2.first[j] + carry, base);
        
        carry = quo_rem[0];
        difference.first.push_back(quo_rem[1]);
        
        i--;
        j--;
    }

    while(i >= 0)
    {
        quo_rem = QuoRem(num1.first[i] + carry, base);
        
        carry = quo_rem[0];
        difference.first.push_back(quo_rem[1]);
        
        i--;
    }
    
    reverse(difference.first.begin(), difference.first.end());
    
    difference = RemovePaddingFromStart(difference);
    difference = RemovePaddingFromEnd(difference);
    
    difference.first.resize(required_precision + difference.first.size() - difference.second, 0);
    difference.second = required_precision;
    
    return difference;
}

pair<vector<int>, int> multiply(pair<vector<int>, int> num1, pair<vector<int>, int> num2, int base, int required_precision)
{
    num1 = RemovePaddingFromStart(num1);
    num2 = RemovePaddingFromStart(num2);
    
    num1 = RemovePaddingFromEnd(num1);
    num2 = RemovePaddingFromEnd(num2);
    
    int k = num1.first.size();
    int l = num2.first.size();
    
    pair<vector<int>, int> product;
    
    product.second = num1.second + num2.second;
    
    int carry;

    reverse(num1.first.begin(), num1.first.end());
    reverse(num2.first.begin(), num2.first.end());

    vector<int> quo_rem;
    
    for(int i = 0; i < k + l; i++)
        product.first.push_back(0);
    
    for(int i = 0; i <= k - 1; i++)
    {
        carry = 0;
        for(int j = 0; j <= l - 1; j++)
        {
            quo_rem = QuoRem((num1.first[i] * num2.first[j]) + product.first[i+j] + carry, base);
            carry = quo_rem[0];
            product.first[i+j] = quo_rem[1];
        }
        product.first[i+l] = carry;
    }
    
    reverse(product.first.begin(), product.first.end());
    
    product = RemovePaddingFromStart(product);
    product = RemovePaddingFromEnd(product);
    
    product.first.resize(required_precision + product.first.size() - product.second, 0);
    product.second = required_precision;
    
    return product;
}

pair<vector<int>, vector<int>> division_int(pair<vector<int>, int> num1, pair<vector<int>, int> num2, int base)
{
    num1 = RemovePaddingFromStart(num1);
    num2 = RemovePaddingFromStart(num2);
    
    int k = num1.first.size();
    int l = num2.first.size();
    
    if(k < l)
    {
        pair<vector<int>, int> quo, rem;
        
        quo.first.push_back(0);
        quo.second = 0;
        
        rem.first = num1.first;
        rem.second = num1.second;
        
        return make_pair(quo.first, rem.first);
    }
    
    int carry;
    
    reverse(num1.first.begin(), num1.first.end());
    reverse(num2.first.begin(), num2.first.end());

    pair<vector<int>, int> quo, rem;
    
    for(int i = 0; i <= k - 1; i++)
        rem.first.push_back(num1.first[i]);
    
    rem.first.push_back(0);
    
    rem.second = 0;
    
    for(int i = 0; i <= k - l; i++)
        quo.first.push_back(0);
    
    quo.second = 0;
    
    vector<int> quo_rem;
    int temp;
    
    for(int i = k - l; i >= 0; i--)
    {
        quo.first[i] = floor(((rem.first[i+l] * base) + rem.first[i+l-1]) / (num2.first[l-1] * 1.0));

        if(quo.first[i] >= base)
            quo.first[i] = base - 1;

        carry = 0;

        for(int j = 0; j <= l - 1; j++)
        {
            temp = rem.first[i+j] - (quo.first[i] * num2.first[j]) + carry;
            quo_rem = QuoRem(temp, base);
            carry = quo_rem[0];
            rem.first[i+j] = quo_rem[1];
        }

        rem.first[i+l] = rem.first[i+l] + carry;

        while(rem.first[i+l] < 0)
        {
            carry = 0;
            
            for(int j = 0; j <= l - 1; j++)
            {
                temp = rem.first[i+j] + num2.first[j] + carry;
                quo_rem = QuoRem(temp, base);
                carry = quo_rem[0];
                rem.first[i+j] = quo_rem[1];
            }

            rem.first[i+l] = rem.first[i+l] + carry;
            quo.first[i] = quo.first[i] - 1;
        }
    }

    reverse(quo.first.begin(), quo.first.end());
    reverse(rem.first.begin(), rem.first.end());
    
    quo = RemovePaddingFromStart(quo);
    rem = RemovePaddingFromStart(rem);
    
    return make_pair(quo.first, rem.first);
}


pair<vector<int>, int> division(pair<vector<int>, int> num1, pair<vector<int>, int> num2, int base, int required_precision)
{
    num1 = RemovePaddingFromStart(num1);
    num2 = RemovePaddingFromStart(num2);
    
    num1 = RemovePaddingFromEnd(num1);
    num2 = RemovePaddingFromEnd(num2);
    
    for(int idx = 0; idx < num2.first.size(); idx++)
    {
        if(num2.first[idx] != 0)
            break;
        num1.first.push_back(0);
        if(num1.second > 0)
            num1.second--;
        num2.first.push_back(0);
        if(num2.second > 0)
            num2.second--;
    }
    
    num1 = RemovePaddingFromStart(num1);
    num2 = RemovePaddingFromStart(num2);
    
    int k = num1.first.size();
    int l = num2.first.size();
    
    if(num1.second > num2.second)
    {
        for(int idx = 1; idx <= num1.second - num2.second; idx++)
        {
            num2.first.push_back(0);
            l++;
        }
        
    }
    else
    {
        for(int idx = 1; idx <= num2.second - num1.second; idx++)
        {
            num1.first.push_back(0);
            k++;
        }
        
    }
    
    int carry;
    
    reverse(num1.first.begin(), num1.first.end());
    reverse(num2.first.begin(), num2.first.end());
    
    pair<vector<int>, int> quotient, remainder;
    
    if(k < l)
        quotient.first.push_back(0);
    
    for(int i = 0; i <= k - l; i++)
        quotient.first.push_back(0);
    
    quotient.second = 0;
    
    for(int i = 0; i <= k - 1; i++)
        remainder.first.push_back(num1.first[i]);
    
    remainder.first.push_back(0);
    
    remainder.second = 0;
    
    vector<int> quo_rem;
    int temp;
    
    for(int i = k - l; i >= 0; i--)
    {
        quotient.first[i] = floor(((remainder.first[i+l] * base) + remainder.first[i+l-1]) / (num2.first[l-1] * 1.0));

        if(quotient.first[i] >= base)
            quotient.first[i] = base - 1;

        carry = 0;

        for(int j = 0; j <= l - 1; j++)
        {
            temp = remainder.first[i+j] - (quotient.first[i] * num2.first[j]) + carry;
            quo_rem = QuoRem(temp, base);
            carry = quo_rem[0];
            remainder.first[i+j] = quo_rem[1];
        }

        remainder.first[i+l] = remainder.first[i+l] + carry;

        while(remainder.first[i+l] < 0)
        {
            carry = 0;
            
            for(int j = 0; j <= l - 1; j++)
            {
                temp = remainder.first[i+j] + num2.first[j] + carry;
                quo_rem = QuoRem(temp, base);
                carry = quo_rem[0];
                remainder.first[i+j] = quo_rem[1];
            }

            remainder.first[i+l] = remainder.first[i+l] + carry;
            quotient.first[i] = quotient.first[i] - 1;
        }
    }

    reverse(quotient.first.begin(), quotient.first.end());
    reverse(remainder.first.begin(), remainder.first.end());
    
    for(int idx = 0; idx < required_precision; idx++)
        remainder.first.push_back(0);
    
    remainder = RemovePaddingFromStart(remainder);
    
    reverse(num2.first.begin(), num2.first.end());
    
    pair<vector<int>, vector<int>> frac_part_res = division_int(remainder, num2, base);
    
    int num_zeros = required_precision - frac_part_res.first.size();
    while(num_zeros > 0)
    {
        quotient.first.push_back(0);
        quotient.second = quotient.second + 1;
        num_zeros = num_zeros - 1;
    }
    
    quotient.first.insert(quotient.first.end(), frac_part_res.first.begin(), frac_part_res.first.end());
    quotient.second = quotient.second + frac_part_res.first.size();
    
    quotient = RemovePaddingFromStart(quotient);
    quotient = RemovePaddingFromEnd(quotient);
    
    quotient.first.resize(required_precision + quotient.first.size() - quotient.second, 0);
    quotient.second = required_precision;
    
    return quotient;
}


pair<vector<int>, int> change_base(pair<vector<int>, int> arr, int start_pres, int base)
{
    pair<vector<int>,int> n;
    n.first = {0};
    n.second = 0;
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

    pair<vector<int>, int> digit;
    int decidig;
    vector<int> d;

    int i;
    for(i = 0; i < start_pres; i++)
    {
        x = multiply(base_v, n, 10, 0);

        decidig = arr.first[i];
        
        digit.first.clear();
        digit.second = 0;
        
        while(decidig > 0)
        {
            digit.first.push_back(decidig % 10);
            decidig /= 10;
        }
        
        reverse(digit.first.begin(), digit.first.end());

        n = addition(x, digit, 10, 0);
    }

    int pwr = 1;
    long long int plc = base;
    pair<vector<int>, int> plc_v;
    while(plc > 0)
    {
        plc_v.first.push_back(plc % 10);
        plc /= 10;
    }
    reverse(plc_v.first.begin(), plc_v.first.end());
    
    plc_v.second = 0;
    
    
    for(; i < arr.first.size(); i++)
    {
        decidig = arr.first[i];
        
        digit.first.clear();
        digit.second = 0;
        
        while(decidig > 0)
        {
            digit.first.push_back(decidig % 10);
            decidig /= 10;
        }
        
        reverse(digit.first.begin(), digit.first.end());
        
        x = division(digit, plc_v, 10, 1000);
       
        n = addition(n, x, 10, 1000);
        pwr++;
        
        plc_v = multiply(plc_v, base_v, 10, 0);
    }
    
    return n;
}


pair<vector<int>, int> square_root(pair<vector<int>, int> num, int base, int required_precision)
{
    
    
    pair<vector<int>, int> dv, ad, y, diff, req_diff;
    
    req_diff.first.push_back(0);
    req_diff.second = 0;

    
    for(int idx = 1; idx <= required_precision - 1; idx++)
    {
        req_diff.first.push_back(0);
        req_diff.second++;
    }

    
    req_diff.first.push_back(1);
    base = 10;
    req_diff.second++;
    
    
    pair<vector<int>, int> half;
    half.first = {0, base / 2};
    half.second = 1;

    pair<vector<int>, int> x;
    x = num;
    
    while(1)
    {
        dv = division(num, x, base, required_precision);
        ad = addition(x, dv, base, required_precision);
        y = multiply(half, ad, base, required_precision);
        
        diff = subtraction(x, y, base, required_precision);
        
        diff.first.resize(required_precision + diff.first.size() - diff.second, 0);
        diff.second = required_precision;
        
        if(isSmallerThan(diff, req_diff))
            break;
        
        x = y;
    }
    
    y.first.resize(required_precision + y.first.size() - y.second, 0);
    y.second = required_precision;
    
    y = change_base(y, y.first.size() - y.second, base);
    
    return y;
}

pair<vector<int>, int> pi(int required_precision, int base)
{
    pair<vector<int>, int> a, b, p, sq_an, inv, sum;
    pair<vector<int>, int> zero, one, two;
    base = 10;
    
    zero.first = {0};
    zero.second = 0;
    
    one.first = {1};
    one.second = 0;
    
    if(base == 2)
        two.first = {1, 0};
    else
        two.first = {2};
    two.second = 0;
    
    pair<vector<int>, int> diff, req_diff;
    
    req_diff.first.push_back(0);
    req_diff.second = 0;
    
    for(int idx = 1; idx <= required_precision - 1; idx++)
    {
        req_diff.first.push_back(0);
        req_diff.second++;
    }
    
    req_diff.first.push_back(1);
    req_diff.second++;
    
    int required_precision_with_guard_digits = ceil(required_precision + log(required_precision + 8));
    
    a = square_root(two, base, required_precision_with_guard_digits);
    b = zero;
    p = addition(a, two, base, required_precision_with_guard_digits);
    
    pair<vector<int>, int> a_next, b_next, p_next;
    
    pair<vector<int>, int> half;
    half.first = {0, base / 2};
    half.second = 1;
    
    while(1)
    {
        sq_an = square_root(a, base, required_precision_with_guard_digits);
        inv = division(one, sq_an, base, required_precision_with_guard_digits);
        a_next = addition(sq_an, inv, base, required_precision_with_guard_digits);
        a_next = division(a_next, two, base, required_precision_with_guard_digits);
        
        sum = addition(a, b, base, required_precision_with_guard_digits);
        b_next = addition(one, b, base, required_precision_with_guard_digits);
        b_next = multiply(b_next, sq_an, base, required_precision_with_guard_digits);
        b_next = division(b_next, sum, base, required_precision_with_guard_digits);
        
        sum = addition(one, b_next, base, required_precision_with_guard_digits);
        p_next = addition(one, a_next, base, required_precision_with_guard_digits);
        p_next = multiply(p_next, p, base, required_precision_with_guard_digits);
        p_next = multiply(p_next, b_next, base, required_precision_with_guard_digits);
        p_next = division(p_next, sum, base, required_precision_with_guard_digits);
        
        diff = subtraction(p_next, p, base, required_precision_with_guard_digits);
        
        diff.first.resize(required_precision + diff.first.size() - diff.second, 0);
        diff.second = required_precision;
        
        if(isSmallerThan(diff, req_diff))
            break;
        
        a = a_next;
        b = b_next;
        p = p_next;
        
    }
    
    p_next.first.resize(required_precision + p_next.first.size() - p_next.second, 0);
    p_next.second = required_precision;
    
    p_next = change_base(p_next, p_next.first.size() - p_next.second, base);
    
    return p_next;
}

int main()
{   
    int id, m, pres;
    cin >> id;
    
    pair<vector<int>, int> result;

    if(id == 1)
    {
        cin >> pres >> m;
        int p = pow(2, m);
        result = pi(pres, p);
    }
    else if(id == 2)
    {
        cin >> pres >> m;
        pair<vector<int>, int> inp;
        inp.first = {2};
        inp.second = 0;
        int p = pow(2, m);
        result = square_root(inp, p, pres);
    }
    
    for(int idx = 0; idx < pres + 1; idx++)
    {
        cout << result.first[idx];
        if(idx == result.first.size() - result.second - 1)
            cout << ".";
    }
    cout << endl;
    
    return 0;
}

