
using SQLite;
using lab_1.lab_3.Entities;
using lab_1.lab_3.Service;

public class SQLiteService : IDbService {

    SQLiteConnection dbConnection = new SQLiteConnection(Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData), @"database.db"),
        SQLiteOpenFlags.ReadWrite | 
        SQLiteOpenFlags.Create | 
        SQLiteOpenFlags.SharedCache);

    public void Init() {
        
        dbConnection.DropTable<Member>();
        dbConnection.DropTable<Team>();
        dbConnection.CreateTable<Member>();
        dbConnection.CreateTable<Team>();

        dbConnection.Insert(new Team { Name = "Dinamo", Sport = "Football" });
        dbConnection.Insert(new Team { Name = "Spartak", Sport = "Footbal" });
        dbConnection.Insert(new Team { Name = "Mercedes", Sport = "Autosport" });
        dbConnection.Insert(new Team { Name = "Ferrari", Sport = "Autosport" });

        
        dbConnection.Insert(new Member { Name = "Kane", Age = 25, Experience = 2, TeamId = 1 });
        dbConnection.Insert(new Member { Name = "Lewandowski", Age = 28, Experience = 3, TeamId = 1 });
        dbConnection.Insert(new Member { Name = "Messi", Age = 32, Experience = 2, TeamId = 1 });
        dbConnection.Insert(new Member { Name = "Suarez", Age = 30, Experience = 1, TeamId = 1 });
        dbConnection.Insert(new Member { Name = "Mbappe", Age = 20, Experience = 3, TeamId = 1 });
        dbConnection.Insert(new Member { Name = "Neymar", Age = 28, Experience = 1, TeamId = 1 });
        dbConnection.Insert(new Member { Name = "Alvarez", Age = 35, Experience = 1, TeamId = 1 });
        dbConnection.Insert(new Member { Name = "Salah", Age = 30, Experience = 1, TeamId = 1 });

                                      
        dbConnection.Insert(new Member { Name = "Kroos", Age = 30, Experience = 2, TeamId = 2 });
        dbConnection.Insert(new Member { Name = "Ramos", Age = 35, Experience = 3, TeamId = 2 });
        dbConnection.Insert(new Member { Name = "Ronaldo", Age = 35, Experience = 1, TeamId = 2 });
        dbConnection.Insert(new Member { Name = "Promes", Age = 30, Experience = 3, TeamId = 2 });
        dbConnection.Insert(new Member { Name = "Benzema", Age = 30, Experience = 1, TeamId = 2 });
        dbConnection.Insert(new Member { Name = "Modric", Age = 35, Experience = 1, TeamId = 2 });
        dbConnection.Insert(new Member { Name = "Isco", Age = 30, Experience = 1, TeamId = 2 });

        dbConnection.Insert(new Member { Name = "Hamilton", Age = 35, Experience = 11, TeamId = 3 });
        dbConnection.Insert(new Member { Name = "Bottas", Age = 30, Experience = 9, TeamId = 3 });
        dbConnection.Insert(new Member { Name = "Toto Wolff", Age = 30, Experience = 7, TeamId = 3 });
                                      
        dbConnection.Insert(new Member { Name = "Vettel", Age = 32, Experience = 10, TeamId = 4 });
        dbConnection.Insert(new Member { Name = "Leclerc", Age = 25, Experience = 8, TeamId = 4 });
        dbConnection.Insert(new Member { Name = "Zak Brown", Age = 30, Experience = 6, TeamId = 4 });
                                
    }

    public IEnumerable<Team> GetAllTeams() {
        return dbConnection.Table<Team>().ToList();
    }

    public IEnumerable<Member> GetTeamMembers(int id) {
        return dbConnection.Table<Member>().Where(m => m.TeamId.Equals(id)).ToList();
    }
}

