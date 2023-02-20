using lab_1.lab_3.Entities;

namespace lab_1.lab_3.Service {
    public interface IDbService {


        void Init();
        IEnumerable<Team> GetAllTeams();
        IEnumerable<Member> GetTeamMembers(int id);




    }
}
