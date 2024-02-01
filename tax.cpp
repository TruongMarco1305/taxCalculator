//Name: Truong Gia Ky Nam
//ID: 2352787
//Email: nam.truonggiaky@hcmut.edu.vn

//Calling the library
#include <iostream>
#include <iomanip>

using namespace std;

//Define the tate of social insurance, medical insurance, unemployment insurance
//and the self-reduce and dependence reduce money
const double socialInsuranceRate = 0.08;
const double medicalInsuranceRate = 0.015;
const double unemploymentInsuranceRate = 0.01;
const double selfReduceConst = 11000000;
const double dependenceReduceConst = 4400000;

//Calculated tax based on the second way show on the taxes'rate table
double taxCalculated(double salary){
    //Define the answer variable tax
    double tax;
    if (salary <= 5e+6){ //taxable income below or equal to 5M VND
        //5% taxable income
        tax = salary * 0.05;
    } else if (salary > 5e+6 && salary <= 10e+6){ //taxable income over 5M and reach 10M
        //10% of taxable income - 0.25M
        tax = salary * 0.1 - 0.25e+6;
    } else if (salary > 10e+6 && salary <= 18e+6){ //taxable income over 10M and reach 18M
        //15% of taxable income - 0.75M
        tax = salary * 0.15 - 0.75e+6;
    } else if (salary > 18e+6 && salary <= 32e+6){ //taxable income over 18M and reach 32M
        //20% of taxable income - 1.65M
        tax = salary * 0.2 - 1.65e+6;
    } else if (salary > 32e+6 && salary <= 52e+6){ //taxable income over 32M and reach 52M
        //25% of taxable income - 3.25M
        tax = salary * 0.25 - 3.25e+6;
    } else if (salary > 52e+6 && salary <= 80e+6){ //taxable income over 52M and reach 80M
        //30% of taxable income - 5.85M
        tax = salary * 0.3 - 5.85e+6;
    } else{// over 80M
        //35% of taxable income - 9.85M
        tax = salary * 0.35 - 9.85e+6;
    }
    return tax;
}

//Calculate the tax of the first 5M of the taxable income 
double taxLevel1(double salary){
    //Define the tax of the first 5M of the taxable income
    double tax1;
    if (salary <= 5e+6){
        //If the taxable income is below 5M, 5% of taxable income
        tax1 = salary * 0.05;
    } else if (salary > 5e+6) {
        //If the taxable income is over 5M, the first 5M is of the taxable income is taken
        tax1 = 5e+6 * 0.05;
    } else if (salary == 0){ //If taxable income is 0
        tax1 = 0;
    }
    //Return the value of the tax of the first 5M of the taxable income
    return tax1;
}

//Calculate the tax of the second 5M of the taxable income
double taxLevel2(double salary){
    //Define the tax of the first 5M of the taxable income
    double tax2;
    if (salary > 5e+6 && salary <= 10e+6){
        //After subtract the first 5M, if the taxable income is below 5M, 10% of taxable income is taken
        tax2 = (salary - 5e+6) * 0.1;
    } else if (salary > 10e+6){
        //If the initial taxable income is over 10M, the second 5M is taken
        tax2 = 5e+6 * 0.1;
    } else if (salary <= 5e+6){
        //If the initial taxable income is under 5M, the tax level 2 is zero
        tax2 = 0;
    }
    //Return the value of the tax of the second 5M of the taxable income
    return tax2;
}

//Calculate the tax of the next 8M of the taxable income
double taxLevel3(double salary){
    //Define the tax of the next 8M of the taxable income
    double tax3;
    if (salary > 10e+6 && salary <= 18e+6){
        //After subtract the 10M before, if the taxable income is below 8M, 15% of taxable income is taken
        tax3 = (salary - 10e+6) * 0.15;
    } else if (salary > 18e+6){
        //If the initial taxable income is over 18M, the 8M part is taken
        tax3 = 8e+6 * 0.15;
    } else if (salary <= 10e+6){
        //If the initial taxable income is under 10M, the tax level 3 is zero
        tax3 = 0;
    }
    //Return the value of the tax of the 8M part of the taxable income
    return tax3;
}

//Calculate the tax of the next 14M of the taxable income
double taxLevel4(double salary){
    //Define the tax of the next 14M of the taxable income
    double tax4;
    if (salary > 18e+6 && salary <= 32e+6){
        //After subtract the 18M before, if the taxable income is below 14M, 20% of taxable income is taken
        tax4 = (salary - 18e+6) * 0.2;
    } else if (salary > 32e+6){
        //If the initial taxable income is over 32M, the 14M part is taken
        tax4 = 14e+6 * 0.2;
    } else if (salary <= 18e+6){
        //If the initial taxable income is under 18M, the tax level 4 is zero
        tax4 = 0;
    }
    //Return the value of the tax of the 14M part of the taxable income
    return tax4;
}

//Calculate the tax of the next 20M of the taxable income
double taxLevel5(double salary){
    //Define the tax of the next 20M of the taxable income
    double tax5;
    if (salary > 32e+6 && salary <= 52e+6){
        //After subtract the 32M before, if the taxable income is below 20M, 25% of taxable income is taken
        tax5 = (salary - 32e+6) * 0.25;
    } else if (salary > 52e+6){
        //If the initial taxable income is over 52M, the 20M part is taken
        tax5 = 20e+6 * 0.25;
    } else if (salary <= 32e+6){
        //If the initial taxable income is under 32M, the tax level 5 is zero
        tax5 = 0;
    }
    //Return the value of the tax of the 20M part of the taxable income
    return tax5;
}

//Calculate the tax of the next 28M of the taxable income
double taxLevel6(double salary){
    //Define the tax of the next 28M of the taxable income
    double tax6;
    if (salary > 52e+6 && salary <= 80e+6){
        //After subtract the 52M before, if the taxable income is below 28M, 30% of taxable income is taken
        tax6 = (salary - 52e+6) * 0.3;
    } else if (salary > 80e+6){
        //If the initial taxable income is over 80M, the 28M part is taken
        tax6 = 28e+6 * 0.3;
    } else if (salary <= 52e+6){
        //If the initial taxable income is under 52M, the tax level 6 is zero
        tax6 = 0;
    }
    //Return the value of the tax of the 28M part of the taxable income
    return tax6;
}

//Calculate the tax of the rest of the taxable income
double taxLevel7(double salary){
    //Define the tax of the rest of the taxable income
    double tax7;
    if (salary > 80e+6){
        //After subtract the 80M before, 35% of taxable income is taken
        tax7 = (salary - 80e+6) * 0.35;
    } else if (salary <= 80e+6){
        //If the initial taxable income is under 80M, the tax level 7 is zero
        tax7 = 0;
    }
    //Return the value of the tax of the rest of the taxable income
    return tax7;
}

int main(){
    //Define the Total Income, the Basic Salary and number of dependence
    double totalSalary, basicSalary, incomeTax;
    int noOfDependence;

    //Set the notification for the success message for the user
    string notification = "Your calculation is complete";

    //Input the the given variable
    cout << "Input the basic salary (in VND): ";
    cin >> basicSalary;
    cout << "Input the total income (in VND): ";
    cin >> totalSalary;
    cout << "Input the number of dependence: ";
    cin >> noOfDependence;

    //If the total income is smaller than the basic salary (in general that is impossible), then the code will
    //still running but at the end, the notification will inform that may be the user have the mistake in input the salary 
    if (basicSalary > totalSalary){
        notification = "Maybe you have misunderstood between basic salary and total salary, please try again.";
    }

    //Calculate the Medical Insurance by taking the Basic Salary times the Medical Insurance Rate
    double medicalInsurance = basicSalary * medicalInsuranceRate;

    //Calculate the Social Insurance by taking the Basic Salary times the Social Insurance Rate
    double socialInsurance = basicSalary * socialInsuranceRate;

    //Calculate the Unemployment Insurance by taking the Basic Salary times the Unemployment Insurance Rate
    double unemploymentInsurance = basicSalary * unemploymentInsuranceRate;

    //Calculate the Dependence Reduce by taking the Number of Dependence times the Dependence Reduce
    double dependenceReduce = noOfDependence * dependenceReduceConst;

    //Calculate the Salary before tax by taking the total salary minus the total insurance
    double salaryBeforeTax = totalSalary - medicalInsurance - socialInsurance - unemploymentInsurance;

    //Calculate the Taxable Income by taking the Salary before tax minus the self reduce and dependence reduce
    double taxableIncome = salaryBeforeTax - selfReduceConst - dependenceReduce;


    //If the taxableIncome is negative, then return to zero
    if (taxableIncome < 0){
        taxableIncome = 0;
    }

    //If the taxable income is zero, the income tax is also zero
    if (taxableIncome == 0){
        incomeTax = 0;
    } else { //If the taxable income is non-zero and positive, return the income tax
        incomeTax = taxCalculated(taxableIncome);
    }

    //Print the value in the form of table
    cout << endl;
    cout << "Type of money" << setw(15) << "" << setw(1) << "Amount" << endl;

    //Print the value of insurance, self reduce, dependence reduce, income before tax, taxable income and income tax, get 3 significant figure
    cout << "Medical Insurance" << setw(11) << "" << setw(1) << fixed << setprecision(3) << medicalInsurance << " (VND)" << endl;
    cout << "Social Insurance" << setw(12) << "" << setw(1) << fixed << setprecision(3) << socialInsurance << " (VND)" << endl;
    cout << "Unemployment Insurance" << setw(6) << "" << setw(1) << fixed << setprecision(3) << unemploymentInsurance << " (VND)" << endl;
    cout << "Income Before Tax" << setw(11) << "" << setw(1) << fixed << setprecision(3) << salaryBeforeTax << " (VND)" << endl;
    cout << "Total self reduce" << setw(11) << "" << setw(1) << fixed << setprecision(3) << selfReduceConst << " (VND)" << endl;
    cout << "Dependence reduce" << setw(11) << "" << setw(1) << fixed << setprecision(3) << dependenceReduce << " (VND)" << endl;
    cout << "Taxable income" << setw(14) << "" << setw(1) << fixed << setprecision(3) << taxableIncome << " (VND)" << endl;
    cout << "TOTAL INCOME TAX (*)"  << setw(8) << "" << setw(1) << fixed << setprecision(3) << incomeTax << " (VND)" << endl;
    
    //Display the value of each tax rate, get 3 significant figure
    cout << endl;
    cout << "(*) is sum of the following calculation" << endl;
    cout << "Tax's income" << setw(18) << "Rate" << setw(13) << "Amount" << endl;
    cout << "To 5M" << setw(23) << "5%" << setw(9) << "" << fixed << setprecision(3) << taxLevel1(taxableIncome) << " (VND)" << endl;
    cout << "Above 5M and to 10M" << setw(10) << "10%" << setw(8) << "" << fixed << setprecision(3) << taxLevel2(taxableIncome) << " (VND)" << endl;
    cout << "Above 10M and to 18M" << setw(9) << "15%" << setw(8) << "" << fixed << setprecision(3) << taxLevel3(taxableIncome) << " (VND)" << endl;
    cout << "Above 18M and to 32M" << setw(9) << "20%" << setw(8) << "" << fixed << setprecision(3) << taxLevel4(taxableIncome) << " (VND)" << endl;
    cout << "Above 32M and to 52M" << setw(9) << "25%" << setw(8) << "" << fixed << setprecision(3) << taxLevel5(taxableIncome) << " (VND)" << endl;
    cout << "Above 52M and to 80M" << setw(9) << "30%" << setw(8) << "" << fixed << setprecision(3) << taxLevel6(taxableIncome) << " (VND)" << endl;
    cout << "Above 80M" << setw(20) << "35%" << setw(8) << "" << fixed << setprecision(3) << taxLevel7(taxableIncome) << " (VND)" << endl;

    //Print the Income tax and the NET salary 
    cout << endl << "So the toal tax you have to pay with the your given information is: " << fixed << setprecision(0) << incomeTax << " (VND)" << endl;
    cout << "Additionally, your NET salary is: " << fixed << setprecision(0) << salaryBeforeTax - incomeTax << " (VND)";

    cout << endl << notification;
    return 0;
}



