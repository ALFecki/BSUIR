
using lab_1.lab_3.Entities;
using lab_1.lab_4.Entities;
using System.Text.Json;

namespace lab_1.lab_4 {
    class RateService : IRateService {

        private HttpClient client;

        public RateService() {
            client = new();

        }

        async Task<IEnumerable<Currency>> GetCurrencies() {
            var rates = new List<Currency>();
            Uri uri = new Uri("https://www.nbrb.by/api/exrates/currencies");
            try {

                HttpResponseMessage response = await client.GetAsync(uri);
                if (response.IsSuccessStatusCode) {
                    string content = await response.Content.ReadAsStringAsync();
                    rates = JsonSerializer.Deserialize<List<Currency>>(content);
                }
                if (rates is not null) {
                    foreach (Currency currency in rates) {
                        if (currency.Cur_DateEnd < DateTime.Now) {
                            rates.Remove(currency);
                        }
                    }
                }
                return rates;

            } catch (Exception) {

                return null;
            }

        }
        public IEnumerable<Rate> GetRates() {
            return null;
        }
    }
}
