using SQLite;

namespace lab_1.lab_3.Entities {

    [Table("Members")]
    public class Member {


        [PrimaryKey, AutoIncrement, Indexed]
        public int Id { get; set; }
        public string Name { get; set; }
        public int Age { get; set; }
        public int Experience { get; set; }
        [Indexed]
        public int TeamId { get; set; }

    }

}
