
using SQLite;

namespace lab_1.lab_3.Entities {

    [Table("Team")]
    public class Team {

        [PrimaryKey, AutoIncrement, Indexed]
        public int Id { get; set; }
        public string Name { get; set; }
        public string Sport { get; set; }


    }
}