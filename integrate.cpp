#include<bits/stdc++.h>

using namespace std;

pair<vector<int>, int> RemovePaddingFromStart(pair<vector<int>, int> num)
{
    if(num.first.size() == 0)   return num;
    int scale_num = num.first.size() - num.second;
    //cout << "scale: " << scale << endl;
    
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
    if(num.first.size() == 0)   return num;
    while((num.first[num.first.size() - 1] == 0) && (num.second != 0))
    {
        num.first.pop_back();
        num.second = num.second - 1;
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
    
    //ret = !(equal(num1.first.begin(), num1.first.end(), num2.first.begin()));
    
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
// works for usigned representation : num1.first and num2.first
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
    /*
    cout << "num1.first: ";
    for(int idx = 0; idx < k; idx++)
        cout << num1.first[idx] << " ";
    cout << endl << "num2.first: ";
    for(int idx = 0; idx < l; idx++)
        cout << num2.first[idx] << " ";
    cout << endl;
    */
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

    
    sum.second = required_precision + 1 - sum.first.size() + sum.second;
  
    sum.first.resize(required_precision + 1, 0);
    
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
    
    cout << "difference in sub after subtraction: " << endl;
    for(int j = 0; j < difference.first.size(); j++)
    {
        cout << difference.first[j];
        if(j == difference.first.size() - difference.second - 1)
            cout << ".";
    }
    cout << endl;
    
    difference = RemovePaddingFromStart(difference);
    difference = RemovePaddingFromEnd(difference);
    
    difference.second = required_precision + 1 - difference.first.size() + difference.second;
   
    difference.first.resize(required_precision + 1, 0);
    
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
    
 
    
    product.second = required_precision + 1 - product.first.size() + product.second;
   
    product.first.resize(required_precision + 1, 0);

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
    
    // Initialise quo.first to 0 as well
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
    
    // Initialise quotient.first to 0 as well
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
    
    
    quotient.second = required_precision + 1 - quotient.first.size() + quotient.second;
  
    quotient.first.resize(required_precision + 1, 0);
    
    return quotient;
    
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
    for(i = 0; i < start_pres; i++)
    {
        x = multiply(base_v, n, 10, 100);

        pair<vector<int>, int> inter = {{arr.first[i]}, 0};
        n = addition(x, inter, 10, 100);

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
        pair<vector<int>, int> inter;
        inter.first = dig_break;
        inter.second = 0;
        x = division(inter, plc_v, 10, 100);
        for(int p = 0; p < 10; p++) cout << x.first[p] << " ";
        cout << endl;
        cout << x.second << endl;
        n = addition(n, x, 10, 100);

        plc_v = multiply(plc_v, base_v, 10, 100);

        

        cout << "changed base\n";
        for(int i = 0; i < n.first.size(); i++)
        {
            cout << n.first[i] << " ";
        }
        cout << endl;
        cout << n.second << endl;
    }
}


pair<vector<int>, int> square_root(pair<vector<int>, int> num, int base, int required_precision)
{
    pair<vector<int>, int> x;
    
    x = num;
    
    pair<vector<int>, int> dv, ad, y, diff, req_diff;
    
    req_diff.first.push_back(0);
    req_diff.second = 0;
    
    for(int idx = 1; idx <= required_precision - 1; idx++)
    {
        req_diff.first.push_back(0);
        req_diff.second++;
    }
    
    req_diff.first.push_back(1);
    req_diff.second++;
    
    pair<vector<int>, int> half;
    half.first = {0, base / 2};
    half.second = 1;
    
    
    while(1)
    {
        dv = division(num, x, base, required_precision);
     
        ad = addition(x, dv, base, required_precision);
      
        y = multiply(half, ad, base, required_precision);
        
        diff = subtraction(x, y, base, required_precision);
        
        diff.second = required_precision + 1 - diff.first.size() + diff.second;
       
        diff.first.resize(required_precision + 1, 0);
        
        
        
        if(isSmallerThan(diff, req_diff))
            break;
        
        
        x = y;
        
    }
    
    
    y.second = required_precision + 1 - y.first.size() + y.second;
    
    y.first.resize(required_precision + 1, 0);
    
    
    return y;
   
}

void pi(int required_precision, int base)
{
    pair<vector<int>, int> a, b, p, sq_an, inv, sum;
    
    pair<vector<int>, int> zero, one, two;
    
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
    
    cout << "a_init: " << endl;
    for(int j = 0; j < required_precision; j++)
    {
        cout << a.first[j];
        if(j == a.first.size() - a.second - 1)
            cout << ".";
    }
    cout << endl;
    
    b = zero;

    
    p = addition(a, two, base, required_precision_with_guard_digits);
    
    
    pair<vector<int>, int> a_next, b_next, p_next;
    
    pair<vector<int>, int> half;
    half.first = {0, base / 2};
    half.second = 1;
    
    int i = 1;
    

    while(1)
    {
        cout << "i: " << i << endl;
        
        // 1st line
        sq_an = square_root(a, base, required_precision_with_guard_digits);
        
        cout << "sq_an: " << endl;
        for(int j = 0; j < sq_an.first.size(); j++)
        {
            cout << sq_an.first[j];
            if(j == sq_an.first.size() - sq_an.second - 1)
                cout << ".";
        }
        cout << endl;
        
        inv = division(one, sq_an, base, required_precision_with_guard_digits);
        a_next = addition(sq_an, inv, base, required_precision_with_guard_digits);
        
        cout << "a_next before div: " << endl;
        for(int j = 0; j < a_next.first.size(); j++)
        {
            cout << a_next.first[j];
            if(j == a_next.first.size() - a_next.second - 1)
                cout << ".";
        }
        cout << endl;
        
        a_next = division(a_next, two, base, required_precision_with_guard_digits);
        
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
        sum = addition(a, b, base, required_precision_with_guard_digits);
        b_next = addition(one, b, base, required_precision_with_guard_digits);
        b_next = multiply(b_next, sq_an, base, required_precision_with_guard_digits);
        b_next = division(b_next, sum, base, required_precision_with_guard_digits);
        
        // 3rd line
        sum = addition(one, b_next, base, required_precision_with_guard_digits);
        p_next = addition(one, a_next, base, required_precision_with_guard_digits);
        p_next = multiply(p_next, p, base, required_precision_with_guard_digits);
        p_next = multiply(p_next, b_next, base, required_precision_with_guard_digits);
        
        cout << "p_next before div: " << endl;
        for(int j = 0; j < p_next.first.size(); j++)
        {
            cout << p_next.first[j];
            if(j == p_next.first.size() - p_next.second - 1)
                cout << ".";
        }
        cout << endl;
        
        p_next = division(p_next, sum, base, required_precision_with_guard_digits);
        
        cout << "p_next after div: " << endl;
        for(int j = 0; j < p_next.first.size(); j++)
        {
            cout << p_next.first[j];
            if(j == p_next.first.size() - p_next.second - 1)
                cout << ".";
        }
        cout << endl;
        
        diff = subtraction(p_next, p, base, required_precision_with_guard_digits);
        
        diff.second = required_precision + 1 - diff.first.size() + diff.second;
        
        diff.first.resize(required_precision + 1, 0);
        
        cout << "i before compare: " << i << endl;
        
        
        if(isSmallerThan(diff, req_diff))
            break;
        
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
    
    
    cout << "Orig base pi: " << endl;
    for(int i = 0; i < required_precision + 1; i++)
    {
        cout << p_next.first[i] << " ";
        if(i == p_next.first.size() - p_next.second - 1)
            cout << "." << " ";
    }
    cout << endl;
    
    change_base(p_next,p_next.first.size() - p_next.second, base);
    
    return;
}
       

int main()
{
    int id, m, pres;
    string str;
    cin >> id;

    if(id == 1)
    {
        cin >> pres >> m;
        int p = pow(2, m);
        pi(pres, p);
    }
    else if(id == 2)
    {
        cin >> pres >> m;
        pair<vector<int>, int> inp;
        if(m == 1)  inp.first = {1, 0};
        else inp.first = {2};
        inp.second = 0;
        int p = pow(2, m);
        square_root(inp, p, pres);
    }
    
    return 0;
}
