struct EmployeeProfile 
{
    char ID[8];
    char FullName[16];
    char Address[16];
    int EducationLevel;
    int BaseSalary;
};

struct AttendanceRecord 
{
    int PaidLeaveDays;
    int UnpaidLeaveDays;
    int OvertimeDays;
};

struct EmployeeNode 
{
    EmployeeProfile info;
    AttendanceRecord attendance;
    double TotalSalary;
    EmployeeNode* pNext;
};

typedef EmployeeNode NODE_EMPLOYEE;

struct EmployeeList 
{
    NODE_EMPLOYEE* pHead;
    NODE_EMPLOYEE* pTail;
};

void InitializeEmployeeList(EmployeeList& list);
NODE_EMPLOYEE* GetEmployeeNode(EmployeeProfile profile, AttendanceRecord record);
void InsertEmployee(EmployeeList& list, EmployeeProfile profile, AttendanceRecord record);
double CalculateExtraSalary(AttendanceRecord record, int EducationLevel);
void CalculateTotalSalary(EmployeeList& list);
void SortByTotalSalary(EmployeeList& list);
void DisplayEmployeeList(EmployeeList list);

void InitializeEmployeeList(EmployeeList& list) 
{
    list.pHead = list.pTail = nullptr;
}

NODE_EMPLOYEE* GetEmployeeNode(EmployeeProfile profile, AttendanceRecord record) 
{
    NODE_EMPLOYEE* p = new NODE_EMPLOYEE;
    if (p != nullptr) 
    {
        p->info = profile;
        p->attendance = record;
        p->TotalSalary = 0;
        p->pNext = nullptr;
    }
    return p;
}

void InsertEmployee(EmployeeList& list, EmployeeProfile profile, AttendanceRecord record) 
{
    NODE_EMPLOYEE* newEmployee = GetEmployeeNode(profile, record);
    if (newEmployee == nullptr) 
    {
        cout << "\nKhong du bo nho";
        return;
    }
    if (list.pHead == nullptr) 
    {
        list.pHead = list.pTail = newEmployee;
    }
    else 
    {
        list.pTail->pNext = newEmployee;
        list.pTail = newEmployee;
    }
}

double CalculateExtraSalary(AttendanceRecord record, int EducationLevel) 
{
    double extraSalary = 0;
    if (EducationLevel == 5) 
    { // Cao học
        extraSalary += 0.10 * 6500000;
    }
    else if (EducationLevel == 6) 
    { // Tiến sĩ
        extraSalary += 0.20 * 6500000;
    }
    extraSalary += 0.04 * record.OvertimeDays * 6500000;
    extraSalary -= 0.04 * record.UnpaidLeaveDays * 6500000;
    if (record.PaidLeaveDays >= 15) 
    {
        extraSalary -= 0.10 * 6500000;
    }
    return extraSalary;
}

void CalculateTotalSalary(EmployeeList& list) 
{
    NODE_EMPLOYEE* current = list.pHead;
    while (current != nullptr) 
    {
        double extraSalary = CalculateExtraSalary(current->attendance, current->info.EducationLevel);
        current->TotalSalary = current->info.BaseSalary + extraSalary;
        current = current->pNext;
    }
}

void SortByTotalSalary(EmployeeList& list) 
{
    if (list.pHead == nullptr || list.pHead->pNext == nullptr)
        return;

    NODE_EMPLOYEE* current, * index;
    EmployeeProfile tempProfile;
    double tempSalary;

    for (current = list.pHead; current != nullptr; current = current->pNext) 
    {
        for (index = current->pNext; index != nullptr; index = index->pNext) 
        {
            if (current->TotalSalary < index->TotalSalary) 
            {
                // Swap EmployeeProfile
                strcpy(tempProfile.ID, current->info.ID);
                strcpy(tempProfile.FullName, current->info.FullName);
                strcpy(tempProfile.Address, current->info.Address);
                tempProfile.EducationLevel = current->info.EducationLevel;
                tempProfile.BaseSalary = current->info.BaseSalary;

                strcpy(current->info.ID, index->info.ID);
                strcpy(current->info.FullName, index->info.FullName);
                strcpy(current->info.Address, index->info.Address);
                current->info.EducationLevel = index->info.EducationLevel;
                current->info.BaseSalary = index->info.BaseSalary;

                strcpy(index->info.ID, tempProfile.ID);
                strcpy(index->info.FullName, tempProfile.FullName);
                strcpy(index->info.Address, tempProfile.Address);
                index->info.EducationLevel = tempProfile.EducationLevel;
                index->info.BaseSalary = tempProfile.BaseSalary;

                // Swap TotalSalary
                tempSalary = current->TotalSalary;
                current->TotalSalary = index->TotalSalary;
                index->TotalSalary = tempSalary;
            }
        }
    }
}

void DisplayEmployeeList(EmployeeList list) 
{
    cout << "\nDanh sach nhan vien va luong thuc linh:";
    cout << "\n===================================================================";
    cout << "\n| " << setw(10) << "Ma NV" << " | " << setw(15) << "Ho va Ten" << " | " << setw(10) << "Luong CB" << " | " << setw(10) << "Phu troi" << " | " << setw(15) << "Luong thuc linh" << " |";
    cout << "\n===================================================================";
    NODE_EMPLOYEE* current = list.pHead;
    while (current != nullptr) {
        cout << "\n| " << setw(10) << current->info.ID << " | " << setw(15) << current->info.FullName << " | " << setw(10) << current->info.BaseSalary << " | " << setw(10) << fixed << setprecision(2) << CalculateExtraSalary(current->attendance, current->info.EducationLevel) << " | " << setw(15) << current->TotalSalary << " |";
        current = current->pNext;
    }
    cout << "\n===================================================================";
}