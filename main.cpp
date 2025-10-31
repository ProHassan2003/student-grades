int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<Person> students(n);

    // Input data for each student
    for (int i = 0; i < n; ++i) {
        cout << "\nStudent " << i + 1 << ":\n";
        cin >> students[i];
    }

    // Choose calculation method
    int method;
    cout << "\nChoose final grade calculation method:\n";
    cout << "1 - Average\n";
    cout << "2 - Median\n";
    cout << "Your choice: ";
    cin >> method;

    // Calculate final grades
    for (auto &s : students) {
        if (method == 2)
            s.calculateMedian();
        else
            s.calculateAverage();
    }

    // Display results
    cout << "\nName        Surname     Final Grade\n";
    cout << "-----------------------------------\n";
    for (auto &s : students)
        cout << s << endl;

    return 0;
}
