
using System.Collections.ObjectModel;
using lab_1.lab_3.Service;
using lab_1.lab_3.Entities;
using System.IO.MemoryMappedFiles;
using System.Linq.Expressions;

namespace lab_1.lab_3 {

    public partial class SQLiteContentPage : ContentPage {
        public IList<Team> teams { get; set; }
        private IDbService service { get; init; }
        public Team SelectedTeam { get; set; }
        public ObservableCollection<Member> members { get; set; }


        public SQLiteContentPage(IDbService dbService) {
            service = dbService;
            service.Init();
            members = new();
            InitializeComponent();
            BindingContext = this;
        }


        private void LoadData(object sender, EventArgs e) {
            teams = service.GetAllTeams().ToList();
            Picker.ItemsSource = null;
            Picker.ItemsSource = (System.Collections.IList)teams;
        }

        private void onSelectedItem(object sender, EventArgs e) {
            var picker = (Picker)sender;
            Team selectedTeam = picker.SelectedItem as Team;
            //members = service.GetTeamMembers(selectedTeam.Id).ToList();
            //TeamList.ItemsSource = null;
            //TeamList.ItemsSource = members;
            if (selectedTeam != null) {
                members.Clear();
                foreach (var member in service.GetTeamMembers(selectedTeam.Id)) {
                    members.Add(member);
                }
            }
        }
    }
}