using lab_1.lab_3.Entities;
using System.Text.Json;


namespace lab_1.lab_4 {
    public class CurrencyService {

        HttpClient client;

        public CurrencyService(HttpClient client) {
            this.client = client;
        }

        public async Task<IEnumerable<Currency>> GetCurrencies() {
            var currencies = new List<Currency>();
            try {

                HttpResponseMessage response = await client.GetAsync(client.BaseAddress);
                if (response.IsSuccessStatusCode) {
                    string content = await response.Content.ReadAsStringAsync();
                    currencies = JsonSerializer.Deserialize<List<Currency>>(content);
                }
                if (currencies is not null) {
                    foreach (Currency currency in currencies) {
                        if (currency.Cur_DateEnd < DateTime.Now) {
                            currencies.Remove(currency);
                        }
                    }
                }
                return currencies;

            } catch (Exception) {

                return null;
            }
        }

    }
}
