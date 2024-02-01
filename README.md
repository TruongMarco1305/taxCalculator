
<!-- PROJECT LOGO -->
<br />
<div align="center">
    <img src="taxes.png" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">Income Tax Calculator</h3>

  <p align="center">
    A cool programme to calculate your taxes based on the law
  </p>
</div>

<!-- ABOUT THE PROJECT -->
## About The Project

This programme is built by C plus plus, and its purpose to help you to calculate your income tax when you go to work. Also, in this programme, this programme also have some cool features like:

* Determining your medical insurance, social insurance and unemployment insurance. 
* Analyzing your budget for every tax's level.  
* Showing how this programme can calculate your final tax and the actual salary you will recieve from your company.
* Display the result in the table form.

Of course, this project is one of my first project as lacking of experience, so there may be some bugs durring the execute procedure and I have try my best to reduce the bugs as possible.

<!-- GETTING STARTED -->
## Getting Started

For this section, I will show you how you can calculate your income tax on your own and how can you use the programme to help you determine your tax.

### Basic salary, Gross Salary and NET Salary 

When you go to work, there will be three kind of salary that you need to take a great consideration:

* Basic salary: The amount of money that your company pay your insurance, including the medical insurance, social insurance and unemployment insurance. 

* Gross salary: The amount of money that including your basic salary, bonus, insurances and income tax. 

* NET salary: The amount of money that your company will pay for you after subtracting the insurance and the income tax. 

### Calculation the Income Tax
Let define the basic salary is BS, the gross salary is GS and the NET salary is NS.

First of all, your total insurance fees including medical insurance fee, social insurance fee and unemployment fee is calculated by:
<p align="center">
Insurance = BS * Rate of Insurance (VND)
</p>
The rate for each type of insurance is display in the table below:

<p align="center">

| Insurance type  | Rate |
| ------------- | ------------- |
| Medical  | 1.5%  |
| Social  | 8%  |
| Unemployment | 1% |  

</p>

_This table is base on Quyết định 595/QĐ-BHXH 2017 về thu BHXH, BHYT, BHTN; quản lý Sổ BHXH, Thẻ BHYT_

After having the total insurance fees, the salary before tax is determined by taking the gross salary minus the insurance fees:
<p align="center">
Salary before tax = GS - Total Insurance (VND)
</p>

For each person, there will exist a fixed self-reduced amount and the number of dependence. The self-reduced amount is 11,000,000 VND and there will be a reduce of 4,400,000 VND for each dependence.

Here, the taxable income (the amount of money use to determine the income tax) is calculated by taking the salary before tax minus the self-reduce and the dependence reduced

<p align="center">
Taxable Income = Salary before tax - 11,000,000 - Number of Dependence * 4,400,000 (VND)
</p>

There are some condition for calculate the Income Tax depends on Number of Dependence and the Gross Salary. The following conditions are cases that you have to pay the Income Tax.

<p align="center">

| No.  | Number of Dependence | Gross salary |
| ------------- | ------------- | -------------|
| 1  | No Dependence | > 11M VND
| 2  | 1 | > 15.4M VND
| 3 | 2 | > 19.8M VND
| 4 | 3 | > 24.2M VND
| 5 | 4 | > 28.4M VND

</p>

_For example, if your gross salary is 15M VND and you have 1 dependence (maybe your son or daughter) then you don't have to pay your income tax_

If you fall into the case that you have to pay the income tax, then your income tax is determined by the following formula:

<p align="center">

| Level  | Taxable Income Range | Tax's rate | Income Tax (Way 1) | Income Tax (Way 2)
| ------------- | ------------------- | -------------| ------------- | ------------- |
| 1  | Up to 5M (VND) | 5% | 0M + 5% * Taxable Income (VND)| 5% * Taxable Income (VND)
| 2  | Over 5M and up to 10M (VND) | 10% | 0.24M + 10% * (Taxable Income - 5M) (VND)| 10% * Taxable Income - 0.25M (VND)|
| 3 | Over 10M and up to 18M (VND) | 15% | 0.75M + 15% * (Taxable Income - 10M) (VND)| 15% * Taxable Income - 0.75M (VND)| 
| 4 | Over 18M and up to 32M (VND) | 20% | 1.95M + 20% * (Taxable Income - 18M) (VND) | 20% * Taxable Income - 1.65M (VND)|
| 5 | Over 32M and up to 52M (VND) | 25% | 4,75M + 25% * (Taxable Income - 32M) (VND)| 25% * Taxable Income - 3,25M (VND)|
| 6 | Over 52M and up to 80M (VND) | 30% | 9,75M + 30% * (Taxable Income - 52M) (VND)| 30% * Taxable Income - 5,85M (VND)|
| 7 | Over 80M (VND) | 40% | 18,15M + 35% * (Taxable Income - 80M) (VND)| 35% * Taxable Income - 9,85M (VND)

</p>

_For example, if your taxable income is 36M VND and you have to pay the income tax. Here is how to find your tax:_

_As your taxable income is in level 5, you can use either of ways to perform the calculation_

_Way 1: Income Tax = 4,75M + 25% * (36M - 32M) = 5.75M (VND)_

_Way 2: Income Tax = 25% * 36M - 3,25M = 5.75M (VND)_

And that is how you can determine your own Income Tax.

<!-- USAGE EXAMPLES -->
## Usage

Now, we have known how to determined your own tax, so let's get coding into the problem. 

When you execute the programme, the terminal will run the following code and ask you to input your basic salary, total income (Gross salary) and number of dependence.

   ```sh
    cout << "Input the basic salary (in VND): ";
    cin >> basicSalary;
    cout << "Input the total income (in VND): ";
    cin >> totalSalary;
    cout << "Input the number of dependence: ";
    cin >> noOfDependence;
   ```

Notice that the basic salary and total income are in the unit Vietnam dong (not thounsand Vietnam dong), so make sure that you type the correct number. (like for 3 million dong, you should input 3 with 6 letter "0", not 3 with 3 letter "0").

After executing, the code will run the following code to compute to give the output and display it in the form of table and for each output, it will display with 3 significant figure. 

In the ouput first table, the programme will display the insurances fee, the income before tax, the total-self and depedence reduce, the taxable income and the total income tax.

In the second table, the programme will analyze the income tax in each tax level, it means that the amount of money for each level.

In the final lines, the programme conclude the tax that the user have to pay and the NET salary that he/she will recive from the company.

The two following examples will show how this programme work:

_Ex1: A person name Ann has basic salary is 10 million dong, total income is 30 million dong, the number of dependence is 2, then type "10000000", "30000000", "2" for each categories. With the given number, the input will look like this:_
 ```
 Input the basic salary (in VND): 10000000
 Input the total income (in VND): 30000000
 Input the number of dependence: 2
 ```
_After execute, the terminal will return the output like this:_
```
Type of money               Amount
Medical Insurance           150000.000 (VND)
Social Insurance            800000.000 (VND)
Unemployment Insurance      100000.000 (VND)
Income Before Tax           28950000.000 (VND)
Total self reduce           11000000.000 (VND)
Dependence reduce           8800000.000 (VND)
Taxable income              9150000.000 (VND)
TOTAL INCOME TAX (*)        665000.000 (VND)

(*) is sum of the following calculation
Tax's income              Rate       Amount
To 5M                     5%         250000.000 (VND)
Above 5M and to 10M       10%        415000.000 (VND)
Above 10M and to 18M      15%        0.000 (VND)
Above 18M and to 32M      20%        0.000 (VND)
Above 32M and to 52M      25%        0.000 (VND)
Above 52M and to 80M      30%        0.000 (VND)
Above 80M                 35%        0.000 (VND)

So the toal tax you have to pay with the your given information is: 665000 (VND)
Additionally, your NET salary is: 28285000 (VND)
Your calculation is complete
```

_Ex2: A person name Bob has basic salary is 9.5 million dong, total income is 50.4 million dong, the number of dependence is 3, then type "9500000", "50400000", "3" for each categories. With the given number, the input will look like this:_
 ```
 Input the basic salary (in VND): 9500000
 Input the total income (in VND): 50400000
 Input the number of dependence: 3
 ```

_After execute, the terminal will return the output like this:_:

```
Type of money               Amount
Medical Insurance           142500.000 (VND)
Social Insurance            760000.000 (VND)
Unemployment Insurance      95000.000 (VND)
Income Before Tax           49402500.000 (VND)
Total self reduce           11000000.000 (VND)
Dependence reduce           13200000.000 (VND)
Taxable income              25202500.000 (VND)
TOTAL INCOME TAX (*)        3390500.000 (VND)

(*) is sum of the following calculation
Tax's income              Rate       Amount
To 5M                     5%         250000.000 (VND)
Above 5M and to 10M       10%        500000.000 (VND)
Above 10M and to 18M      15%        1200000.000 (VND)
Above 18M and to 32M      20%        1440500.000 (VND)
Above 32M and to 52M      25%        0.000 (VND)
Above 52M and to 80M      30%        0.000 (VND)
Above 80M                 35%        0.000 (VND)

So the toal tax you have to pay with the your given information is: 3390500 (VND)
Additionally, your NET salary is: 46012000 (VND)
Your calculation is complete
```
A common mistake that I found is sometimes, the user make the basic salary greater than the total salary. So I have put the notification at the end of the output to inform the user that they might have the wrong input

_In Bob example, if he typed at the basic salary is 30000000 and the total salary is 10000000, the programme will still running but the output will have differences:_
```
Type of money               Amount
Medical Insurance           450000.000 (VND)
Social Insurance            2400000.000 (VND)
Unemployment Insurance      300000.000 (VND)
Income Before Tax           6850000.000 (VND)
Total self reduce           11000000.000 (VND)
Dependence reduce           0.000 (VND)
Taxable income              0.000 (VND)
TOTAL INCOME TAX (*)        0.000 (VND)

(*) is sum of the following calculation
Tax's income              Rate       Amount
To 5M                     5%         0.000 (VND)
Above 5M and to 10M       10%        0.000 (VND)
Above 10M and to 18M      15%        0.000 (VND)
Above 18M and to 32M      20%        0.000 (VND)
Above 32M and to 52M      25%        0.000 (VND)
Above 52M and to 80M      30%        0.000 (VND)
Above 80M                 35%        0.000 (VND)

So the toal tax you have to pay with the your given information is: 0 (VND)
Additionally, your NET salary is: 6850000 (VND)
Maybe you have misunderstood between basic salary and total salary, please try again.
```
I hope that these instruction will give you a clear understanding about my programme.

If you wish how I can perform these calculation through coding, you can check the comments in the source code file. 




<!-- CONTACT -->
## Contact

Truong Gia Ky Nam - [Truong Gia Ky Nam](https://www.facebook.com/TruongGiaKyNam) - nam.truonggiaky@hcmut.edu.vn

Project Link: [https://github.com/your_username/repo_name](https://github.com/your_username/repo_name)





<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

Here is the documents that I use for creating this project:

* [Công cụ tính Thuế thu nhập cá nhân chuẩn 2024](https://www.topcv.vn/tinh-thue-thu-nhap-ca-nhan)
* [[TIỆN ÍCH] Tính thuế thu nhập cá nhân 2024](https://thuvienphapluat.vn/tien-ich/tinh-thue-thu-nhap-ca-nhan.html)
* [Hướng dẫn tính thuế thu nhập cá nhân 2023 | thuế tncn | Kiến Thức 4.0](https://www.youtube.com/watch?v=rTF5p4EUor0)
* [Best README Template](hhttps://github.com/othneildrew/Best-README-Template?fbclid=IwAR3qz_-xMdX5yMAqISBgXn10pS8KU2nHc0Ir0payk1-e_KRUV8IDm-aOIak)







