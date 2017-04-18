# coding: utf-8
require 'oga'
require 'open-uri'

def countyear(year, bc = false, wiki = "https://ja.wikipedia.org/wiki/")
  uri = URI.escape((wiki + (bc ? "紀元前" : "") + year.to_s + "年"))
  begin
    open(uri) { |handle|
      doc = Oga.parse_html(handle)
      text = doc.xpath('//div[@id="mw-content-text"]').text
      text.length
    }
  rescue
    0
  end
end

open("year.csv", "w") { |out| 
  50000.times { |year|
    puts year
    out.puts year.to_s + "," + countyear(year).to_s
  }
}
