using System.Reflection;
using _153503_Skvortsov_Lab6;

Employee[] employees = {
    new Employee("Ivan", 20, true),
    new Employee("Petr", 30, true),
    new Employee("Anna", 25, false)};

List<Employee> list = new(employees);

Assembly asm = Assembly.LoadFrom("FileService.dll");

Type type = asm.GetType("FileService.Services.FileService`1").MakeGenericType(new[] { typeof(Employee) });

if (type != null) {
    MethodInfo save = type.GetMethod("SaveData");
    MethodInfo read = type.GetMethod("ReadFile");
    if (save != null && read !=null) {
        save.Invoke(Activator.CreateInstance(type), new object[] { list, "employees.json" });
        var result = read.Invoke(Activator.CreateInstance(type), new object[] { "employees.json" });
        Console.WriteLine("!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        foreach (var item in (IEnumerable<Employee>)result) {
            Console.WriteLine($"Name: {item.Name}");
            Console.WriteLine($"Age: {item.Age}");
            Console.WriteLine($"Gender: {item.Gender}");
            Console.WriteLine("====================================");
        }
    }
}






