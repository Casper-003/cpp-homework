#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <typeinfo>

using namespace std;

// 验证性别
char validateGender(char gender)
{
    while (gender != 'M' && gender != 'F')
    {
        cout << "输入有误，请重新输入性别(M/F): ";
        cin >> gender;
    }
    return gender;
}

// 验证级别
int validateLevel(int level)
{
    while (level < 1 || level > 10)
    {
        cout << "输入有误，请重新输入级别(1-10): ";
        cin >> level;
    }
    return level;
}

// 验证是否大于0
double validateNum(double num)
{
    while (num <= 0)
    {
        cout << "输入有误，请重新输入: ";
        cin >> num;
    }
    return num;
}

// 抽象基类 - 员工
class Employee
{
public:
    string id;   // 员工编号
    string name; // 姓名
    char gender; // 性别
    int level;   // 级别

public:
    Employee(string id = "", string name = "", char gender = 'M', int level = 1)
        : id(id), name(name), gender(gender), level(level) {
    }

    virtual ~Employee() {}

    // 纯虚函数
    virtual double calsalary() const = 0;

    virtual void input() = 0;

    virtual void display() const = 0;

    virtual string getType() const = 0;

    // getter函数
    string getId() const { return id; }

    string getName() const { return name; }

    char getGender() const { return gender; }
};

// 总经理类
class GeneralManager : public Employee
{
private:
    double fixedSalary; // 固定月薪

public:
    GeneralManager() : Employee() {}

    void input()
    {
        cout << "请输入员工编号: ";
        cin >> id;
        cout << "请输入姓名: ";
        cin >> name;
        cout << "请输入性别(M/F): ";
        cin >> gender;

        gender = validateGender(gender);
        cout << "请输入级别(1-10): ";
        cin >> level;
        level = validateLevel(level);

        cout << "请输入固定月薪: ";
        cin >> fixedSalary;
        fixedSalary = validateNum(fixedSalary);
    }

    double calsalary() const
    {
        return fixedSalary;
    }

    void display() const
    {
        cout << left << setw(10) << id
            << setw(10) << name
            << setw(6) << gender
            << setw(6) << level
            << setw(10) << "总经理"
            << setw(10) << calsalary() << endl;
    }

    string getType() const
    {
        return "总经理";
    }

    double getFixedSalary() const { return fixedSalary; }

    void setFixedSalary(double salary) { fixedSalary = salary; }
};

// 售前工程师类
class PresaleEngineer : public Employee
{
private:
    int workDays;       // 工作天数
    double dailySalary; // 日薪

public:
    PresaleEngineer() : Employee() {}

    void input()
    {
        cout << "请输入员工编号: ";
        cin >> id;
        cout << "请输入姓名: ";
        cin >> name;
        cout << "请输入性别(M/F): ";
        cin >> gender;
        gender = validateGender(gender);
        cout << "请输入级别(1-10): ";
        cin >> level;
        level = validateLevel(level);
        cout << "请输入工作天数: ";
        cin >> workDays;

        cout << "请输入日薪: ";
        cin >> dailySalary;
        dailySalary = validateNum(dailySalary);
    }

    double calsalary() const
    {
        return workDays * dailySalary;
    }

    void display() const
    {
        cout << left << setw(10) << id
            << setw(10) << name
            << setw(6) << gender
            << setw(6) << level
            << setw(10) << "售前工程师"
            << setw(10) << calsalary() << endl;
    }

    string getType() const
    {
        return "售前工程师";
    }

    int getWorkDays() const { return workDays; }

    double getDailySalary() const { return dailySalary; }

    void setWorkData(int days, double salary)
    {
        workDays = days;
        dailySalary = salary;
    }
};

// 销售经理类
class SalesManager : public Employee
{
private:
    double fixedSalary; // 固定月薪
    double commission;  // 提成

public:
    SalesManager() : Employee() {}

    void input()
    {
        cout << "请输入员工编号: ";
        cin >> id;
        cout << "请输入姓名: ";
        cin >> name;

        cout << "请输入性别(M/F): ";
        cin >> gender;
        gender = validateGender(gender);
        cout << "请输入级别(1-10): ";
        cin >> level;
        level = validateLevel(level);
        cout << "请输入固定月薪: ";
        cin >> fixedSalary;
        fixedSalary = validateNum(fixedSalary);
        cout << "请输入提成: ";
        cin >> commission;
        commission = validateNum(commission);
    }

    double calsalary() const
    {
        return fixedSalary + commission;
    }

    void display() const
    {
        cout << left << setw(10) << id
            << setw(10) << name
            << setw(6) << gender
            << setw(6) << level
            << setw(10) << "销售经理"
            << setw(10) << calsalary() << endl;
    }

    string getType() const
    {
        return "销售经理";
    }

    double getFixedSalary() const { return fixedSalary; }

    double getCommission() const { return commission; }

    void setSalaryData(double salary, double comm)
    {
        fixedSalary = salary;
        commission = comm;
    }
};

// 售后工程师类
class AfterSaleEngineer : public Employee
{
private:
    int workHours;     // 工作小时数
    double hourlyRate; // 时薪

public:
    AfterSaleEngineer() : Employee() {}

    void input()
    {
        cout << "请输入员工编号: ";
        cin >> id;
        cout << "请输入姓名: ";
        cin >> name;
        cout << "请输入性别(M/F): ";
        cin >> gender;
        gender = validateGender(gender);
        cout << "请输入级别(1-10): ";
        cin >> level;
        level = validateLevel(level);
        cout << "请输入工作小时数: ";
        cin >> workHours;
        cout << "请输入时薪: ";
        cin >> hourlyRate;
        hourlyRate = validateNum(hourlyRate);
    }

    double calsalary() const
    {
        return workHours * hourlyRate;
    }

    void display() const
    {
        cout << left << setw(10) << id
            << setw(10) << name
            << setw(6) << gender
            << setw(6) << level
            << setw(10) << "售后工程师"
            << setw(10) << calsalary() << endl;
    }

    string getType() const
    {
        return "售后工程师";
    }

    int getWorkHours() const { return workHours; }

    double getHourlyRate() const { return hourlyRate; }

    void setWorkData(int hours, double rate)
    {
        workHours = hours;
        hourlyRate = rate;
    }
};

// 销售助理类
class SalesAssistant : public Employee
{
private:
    double salesAmount;    // 销售额
    double commissionRate; // 提成比例

public:
    SalesAssistant() : Employee() {}

    void input()
    {
        cout << "请输入员工编号: ";
        cin >> id;
        cout << "请输入姓名: ";
        cin >> name;
        cout << "请输入性别(M/F): ";
        cin >> gender;
        gender = validateGender(gender);
        cout << "请输入级别(1-10): ";
        cin >> level;
        level = validateLevel(level);
        cout << "请输入销售额: ";
        cin >> salesAmount;
        salesAmount = validateNum(salesAmount);
        cout << "请输入提成比例(0-1): ";
        cin >> commissionRate;
        while (commissionRate < 0 || commissionRate > 1)
        {
            cout << "提成比例不合法，请重新输入: ";
            cin >> commissionRate;
        }
    }

    double calsalary() const
    {
        return salesAmount * commissionRate;
    }

    void display() const
    {
        cout << left << setw(10) << id
            << setw(10) << name
            << setw(6) << gender
            << setw(6) << level
            << setw(10) << "销售助理"
            << setw(10) << calsalary() << endl;
    }

    string getType() const
    {
        return "销售助理";
    }

    double getSalesAmount() const { return salesAmount; }

    double getCommissionRate() const { return commissionRate; }

    void setSalesData(double amount, double rate)
    {
        salesAmount = amount;
        commissionRate = rate;
    }
};

// 销售专员类
class Salesman : public Employee
{
private:
    double salesAmount;    // 销售额
    double commissionRate; // 提成比例

public:
    Salesman() : Employee() {}

    void input()
    {
        cout << "请输入员工编号: ";
        cin >> id;
        cout << "请输入姓名: ";
        cin >> name;
        cout << "请输入性别(M/F): ";
        cin >> gender;
        gender = validateGender(gender);
        cout << "请输入级别(1-10): ";
        cin >> level;
        level = validateLevel(level);
        cout << "请输入销售额: ";
        cin >> salesAmount;
        salesAmount = validateNum(salesAmount);
        cout << "请输入提成比例(0-1): ";
        cin >> commissionRate;

        while (commissionRate < 0 || commissionRate > 1)
        {
            cout << "提成比例不合法，请重新输入: ";
            cin >> commissionRate;
        }
    }

    double calsalary() const
    {
        return salesAmount * commissionRate;
    }

    void display() const
    {
        cout << left << setw(10) << id
            << setw(10) << name
            << setw(6) << gender
            << setw(6) << level
            << setw(10) << "销售专员"
            << setw(10) << calsalary() << endl;
    }

    string getType() const
    {
        return "销售专员";
    }

    double getSalesAmount() const { return salesAmount; }

    double getCommissionRate() const { return commissionRate; }

    void setSalesData(double amount, double rate)
    {
        salesAmount = amount;
        commissionRate = rate;
    }
};

// 员工管理类
class Manage
{
private:
    static const int MAX_EMPLOYEES = 100;
    Employee* employees[MAX_EMPLOYEES];
    int count;

public:
    Manage() : count(0) {}

    ~Manage()
    {
        for (int i = 0; i < count; i++)
        {
            delete employees[i];
        }
    }

    // 添加员工
    bool addEmployee()
    {
        if (count >= MAX_EMPLOYEES)
        {
            cout << "员工数量已达上限！" << endl;
            return false;
        }

        cout << "\n请选择要添加的员工类型：" << endl;
        cout << "1. 总经理" << endl;
        cout << "2. 售前工程师" << endl;
        cout << "3. 售后工程师" << endl;
        cout << "4. 销售助理" << endl;
        cout << "5. 销售专员" << endl;
        cout << "6. 销售经理" << endl;

        int choice;
        cin >> choice;

        Employee* emp;
        switch (choice)
        {
        case 1:
            emp = new GeneralManager();
            break;
        case 2:
            emp = new PresaleEngineer();
            break;
        case 3:
            emp = new AfterSaleEngineer();
            break;
        case 4:
            emp = new SalesAssistant();
            break;
        case 5:
            emp = new Salesman();
            break;
        case 6:
            emp = new SalesManager();
            break;
        default:
            cout << "无效的选择！" << endl;
            return false;
        }

        emp->input();

        // 检查编号是否重复
        for (int i = 0; i < count; i++)
        {
            if (employees[i]->getId() == emp->getId())
            {
                cout << "员工编号重复！，已取消添加" << endl;
                delete emp;
                return false;
            }
        }

        employees[count++] = emp;
        cout << "添加成功！" << endl;
        return true;
    }

    // 显示所有员工
    void displayAll() const
    {
        if (count == 0)
        {
            cout << "没有员工记录！" << endl;
            return;
        }

        cout << "\n所有员工信息：" << endl;
        cout << left << setw(10) << "编号"
            << setw(10) << "姓名"
            << setw(6) << "性别"
            << setw(6) << "级别"
            << setw(10) << "职位"
            << setw(10) << "工资" << endl;
        cout << string(52, '-') << endl;

        for (int i = 0; i < count; i++)
        {
            employees[i]->display();
        }
    }

    // 查找员工
    int findEmployee(const string& key) const
    {
        for (int i = 0; i < count; i++)
        {
            if (employees[i]->getId() == key || employees[i]->getName() == key)
            {
                return i;
            }
        }
        return -1;
    }

    // 删除员工
    bool del(const string& key)
    {
        int index = findEmployee(key);
        if (index == -1)
        {
            cout << "未找到该员工！" << endl;
            return false;
        }

        delete employees[index];
        for (int i = index; i < count - 1; i++)
        {
            employees[i] = employees[i + 1];
        }
        count--;
        cout << "删除成功！" << endl;
        return true;
    }

    // 统计信息
    void statis() const
    {
        if (count == 0)
        {
            cout << "没有员工记录！" << endl;
            return;
        }
        int typeCount[6] = { 0 };   // 各类型员工数量
        int genderCount[2] = { 0 }; // 性别统计
        double totalSalary = 0;
        double maxSalary = 0;
        double minSalary = employees[0]->calsalary();
        for (int i = 0; i < count; i++)
        {
            // 统计类型
            if (employees[i]->getType() == "总经理")
                typeCount[0]++;
            else if (employees[i]->getType() == "售前工程师")
                typeCount[1]++;
            else if (employees[i]->getType() == "售后工程师")
                typeCount[2]++;
            else if (employees[i]->getType() == "销售助理")
                typeCount[3]++;
            else if (employees[i]->getType() == "销售专员")
                typeCount[4]++;
            else if (employees[i]->getType() == "销售经理")
                typeCount[5]++;
            // 统计性别
            if (employees[i]->getGender() == 'M')
                genderCount[0]++;
            else
                genderCount[1]++;
            // 统计工资
            double salary = employees[i]->calsalary();
            totalSalary += salary;
            if (salary > maxSalary)
                maxSalary = salary;
            if (salary < minSalary)
                minSalary = salary;
        }
        cout << "\n统计信息：" << endl;
        cout << "总人数：" << count << endl;
        cout << "总经理人数：" << typeCount[0] << endl;
        cout << "售前工程师人数：" << typeCount[1] << endl;
        cout << "售后工程师人数：" << typeCount[2] << endl;
        cout << "销售助理人数：" << typeCount[3] << endl;
        cout << "销售专员人数：" << typeCount[4] << endl;
        cout << "销售经理人数：" << typeCount[5] << endl;
        cout << "男性员工人数：" << genderCount[0] << endl;
        cout << "女性员工人数：" << genderCount[1] << endl;
        cout << "平均工资：" << totalSalary / count << endl;
        cout << "最高工资：" << maxSalary << endl;
        cout << "最低工资：" << minSalary << endl;
    }

    void displayemployee(int index) const
    {
        if (index >= 0 && index < count)
        {
            cout << left << setw(10) << "编号"
                << setw(10) << "姓名"
                << setw(6) << "性别"
                << setw(6) << "级别"
                << setw(10) << "职位"
                << setw(10) << "工资" << endl;
            cout << string(52, '-') << endl;
            employees[index]->display();
        }
    }

    // 保存员工数据到文件
    void saveToFiles() const
    {
        ofstream gmFile("general_manager.txt");
        ofstream peFile("presale_engineer.txt");
        ofstream aeFile("aftersale_engineer.txt");
        ofstream saFile("sales_assistant.txt");
        ofstream smFile("salesman.txt");
        ofstream mgFile("sales_manager.txt");
        for (int i = 0; i < count; i++)
        {
            ofstream& outFile = getFileStream(employees[i]->getType(),
                gmFile, peFile, aeFile, saFile, smFile, mgFile);
            // 保存基本信息
            outFile << employees[i]->getId() << " "
                << employees[i]->getName() << " "
                << employees[i]->getGender() << " "
                << employees[i]->level << " ";

            // 保存特定类型的信息
            if (GeneralManager* gm = dynamic_cast<GeneralManager*>(employees[i]))
            {
                outFile << gm->getFixedSalary();
            }
            else if (PresaleEngineer* pe = dynamic_cast<PresaleEngineer*>(employees[i]))
            {
                outFile << pe->getWorkDays() << " " << pe->getDailySalary();
            }
            else if (AfterSaleEngineer* ae = dynamic_cast<AfterSaleEngineer*>(employees[i]))
            {
                outFile << ae->getWorkHours() << " " << ae->getHourlyRate();
            }
            else if (SalesAssistant* sa = dynamic_cast<SalesAssistant*>(employees[i]))
            {
                outFile << sa->getSalesAmount() << " " << sa->getCommissionRate();
            }
            else if (Salesman* sm = dynamic_cast<Salesman*>(employees[i]))
            {
                outFile << sm->getSalesAmount() << " " << sm->getCommissionRate();
            }
            else if (SalesManager* mg = dynamic_cast<SalesManager*>(employees[i]))
            {
                outFile << mg->getFixedSalary() << " " << mg->getCommission();
            }
            outFile << endl;
        }
    }

    // 从文件加载员工数据
    void loadFromFiles()
    {
        // 清除现有数据
        for (int i = 0; i < count; i++)
        {
            delete employees[i];
        }
        count = 0;

        // 从六个文件加载数据
        loadEmployeesFromFile<GeneralManager>("general_manager.txt");
        loadEmployeesFromFile<PresaleEngineer>("presale_engineer.txt");
        loadEmployeesFromFile<AfterSaleEngineer>("aftersale_engineer.txt");
        loadEmployeesFromFile<SalesAssistant>("sales_assistant.txt");
        loadEmployeesFromFile<Salesman>("salesman.txt");
        loadEmployeesFromFile<SalesManager>("sales_manager.txt");
    }

    // 编辑员工方法
    bool editEmployee(const string& key)
    {
        int index = findEmployee(key);
        if (index == -1)
        {
            cout << "未找到该员工！" << endl;
            return false;
        }

        cout << "当前员工信息：" << endl;
        displayemployee(index);

        Employee* oldEmp = employees[index];
        string type = oldEmp->getType();

        cout << "\n请选择要修改的信息：" << endl;
        cout << "1. 姓名" << endl;
        cout << "2. 性别" << endl;
        cout << "3. 级别" << endl;
        cout << "4. 薪资相关信息" << endl;
        cout << "0. 取消" << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 0:
            return false;
        case 1:
        {
            cout << "请输入新的姓名：";
            cin >> oldEmp->name;
            break;
        }
        case 2:
        {
            cout << "请输入新的性别(M/F)：";
            cin >> oldEmp->gender;
            oldEmp->gender = validateGender(oldEmp->gender);
            break;
        }
        case 3:
        {
            cout << "请输入新的级别(1-10)：";
            cin >> oldEmp->level;
            oldEmp->level = validateLevel(oldEmp->level);
            break;
        }
        case 4:
        {
            if (GeneralManager* gm = dynamic_cast<GeneralManager*>(oldEmp))
            {
                cout << "请输入新的固定月薪：";
                double salary;
                cin >> salary;
                gm->setFixedSalary(validateNum(salary));
            }
            else if (PresaleEngineer* pe = dynamic_cast<PresaleEngineer*>(oldEmp))
            {
                int days;
                double daily;
                cout << "请输入新的工作天数：";
                cin >> days;
                cout << "请输入新的日薪：";
                cin >> daily;
                pe->setWorkData(days, validateNum(daily));
            }
            else if (AfterSaleEngineer* ae = dynamic_cast<AfterSaleEngineer*>(oldEmp))
            {
                int hours;
                double rate;
                cout << "请输入新的工作小时数：";
                cin >> hours;
                cout << "请输入新的时薪：";
                cin >> rate;
                ae->setWorkData(hours, validateNum(rate));
            }
            else if (SalesAssistant* sa = dynamic_cast<SalesAssistant*>(oldEmp))
            {
                double amount, rate;
                cout << "请输入新的销售额：";
                cin >> amount;
                cout << "请输入新的提成比例(0-1)：";
                cin >> rate;
                while (rate < 0 || rate > 1)
                {
                    cout << "提成比例不合法，请重新输入：";
                    cin >> rate;
                }
                sa->setSalesData(validateNum(amount), rate);
            }
            else if (Salesman* sm = dynamic_cast<Salesman*>(oldEmp))
            {
                double amount, rate;
                cout << "请输入新的销售额：";
                cin >> amount;
                cout << "请输入新的提成比例(0-1)：";
                cin >> rate;
                while (rate < 0 || rate > 1)
                {
                    cout << "提成比例不合法，请重新输入：";
                    cin >> rate;
                }
                sm->setSalesData(validateNum(amount), rate);
            }
            else if (SalesManager* sm = dynamic_cast<SalesManager*>(oldEmp))
            {
                double salary, commission;
                cout << "请输入新的固定月薪：";
                cin >> salary;
                cout << "请输入新的提成：";
                cin >> commission;
                sm->setSalaryData(validateNum(salary), validateNum(commission));
            }
            break;
        }
        default:
            cout << "无效的选择！" << endl;
            return false;
        }

        cout << "修改成功！" << endl;
        return true;
    }

private:
    // 获取对应的文件流
    static ofstream& getFileStream(const string& type,
        ofstream& gmFile, ofstream& peFile, ofstream& aeFile,
        ofstream& saFile, ofstream& smFile, ofstream& mgFile)
    {
        if (type == "总经理")
            return gmFile;
        if (type == "售前工程师")
            return peFile;
        if (type == "售后工程师")
            return aeFile;
        if (type == "销售助理")
            return saFile;
        if (type == "销售专员")
            return smFile;
        return mgFile;
    }

    // 从文件加载特定类型的员工
    template <typename T>
    void loadEmployeesFromFile(const string& filename)
    {
        ifstream inFile(filename.c_str());
        if (!inFile)
            return;
        string id, name;
        char gender;
        int level;
        while (inFile >> id >> name >> gender >> level)
        {
            if (count >= MAX_EMPLOYEES)
                break;
            T* emp = new T();
            static_cast<Employee*>(emp)->id = id;
            static_cast<Employee*>(emp)->name = name;
            static_cast<Employee*>(emp)->gender = gender;
            static_cast<Employee*>(emp)->level = level;

            // 读取特定类型的额外数据
            if (typeid(T) == typeid(GeneralManager))
            {
                double salary;
                inFile >> salary;
                dynamic_cast<GeneralManager*>(emp)->setFixedSalary(salary);
            }
            else if (typeid(T) == typeid(PresaleEngineer))
            {
                int days;
                double daily;
                inFile >> days >> daily;
                dynamic_cast<PresaleEngineer*>(emp)->setWorkData(days, daily);
            }
            else if (typeid(T) == typeid(AfterSaleEngineer))
            {
                int hours;
                double rate;
                inFile >> hours >> rate;
                dynamic_cast<AfterSaleEngineer*>(emp)->setWorkData(hours, rate);
            }
            else if (typeid(T) == typeid(SalesAssistant))
            {
                double amount, rate;
                inFile >> amount >> rate;
                dynamic_cast<SalesAssistant*>(emp)->setSalesData(amount, rate);
            }
            else if (typeid(T) == typeid(Salesman))
            {
                double amount, rate;
                inFile >> amount >> rate;
                dynamic_cast<Salesman*>(emp)->setSalesData(amount, rate);
            }
            else if (typeid(T) == typeid(SalesManager))
            {
                double salary, commission;
                inFile >> salary >> commission;
                dynamic_cast<SalesManager*>(emp)->setSalaryData(salary, commission);
            }

            employees[count++] = emp;
        }
    }
};

int main()
{
    Manage em;
    int choice;
    while (true)
    {
        cout << "\n========================================" << endl;
        cout << "                 员工管理系统" << endl;
        cout << "========================================" << endl;
        cout << "1. 添加员工" << endl;
        cout << "2. 显示所有员工" << endl;
        cout << "3. 查找员工" << endl;
        cout << "4. 删除员工" << endl;
        cout << "5. 统计信息" << endl;
        cout << "6. 保存数据" << endl;
        cout << "7. 加载数据" << endl;
        cout << "8. 编辑员工" << endl;
        cout << "0. 退出" << endl;
        cout << "========================================" << endl;
        cout << "请选择操作：";

        cin >> choice;

        string searchKey;
        switch (choice)
        {
        case 0:
            cout << "感谢使用！" << endl;
            return 0;
        case 1:
            em.addEmployee();
            break;
        case 2:
            em.displayAll();
            break;
        case 3:
            cout << "请输入要查找的员工编号或姓名：";
            cin >> searchKey;
            {
                int index = em.findEmployee(searchKey);
                if (index != -1)
                {
                    cout << "找到该员工：" << endl;
                    em.displayemployee(index);
                }
                else
                {
                    cout << "未找到该员工！" << endl;
                }
            }
            break;
        case 4:
            cout << "请输入要删除的员工编号或姓名：";
            cin >> searchKey;
            em.del(searchKey);
            break;
        case 5:
            em.statis();
            break;
        case 6:
            em.saveToFiles();
            cout << "数据已保存到文件！" << endl;
            break;
        case 7:
            em.loadFromFiles();
            cout << "数据已从文件加载！" << endl;
            break;
        case 8:
            cout << "请输入要编辑的员工编号或姓名：";
            cin >> searchKey;
            em.editEmployee(searchKey);
            break;
        default:
            cout << "无效的选择！" << endl;
        }
    }
}