import sys, os, time
import pyperclip
import argparse
from selenium import webdriver
from selenium.webdriver.firefox.options import Options
from selenium.webdriver.common.keys import Keys
from urllib import parse
from tqdm import tqdm

class Crawler():
    def __init__(self):
        self.chromedriver_path = "./chromedriver"
        self.save_path = os.getcwd()
        self.id = ''
        self.pw = ''
        self.level = ''
        self.language = ''
        self.file_extension = ''
        self.wait = 20

        self.parser()
        self.printInfo()

        options = webdriver.ChromeOptions()
        options.add_argument('headless')
        self.driver = webdriver.Chrome(self.chromedriver_path, chrome_options=options)
        
        os.makedirs(self.save_path, exist_ok=True)

    def parser(self):
        parser = argparse.ArgumentParser(description='Progarmmers Code Crawler')
        parser.add_argument('--id', dest='id', required=True, help='Programmers login id')
        parser.add_argument('--pw', dest='pw', required=True, help='Programmers login pw')
        parser.add_argument('--lang', dest='language', help='Language', default='cpp')
        parser.add_argument('--level', dest='level', help='Problem Level', default='1')
        parser.add_argument('--save_path', dest='save_path', help='Save Path', default=self.save_path)
        parser.add_argument('--fe', dest='file_extension', help='File Extension  ex)[c,cpp,js...]', default='cpp')
        
        args = parser.parse_args()
        self.id = args.id
        self.pw = args.pw
        self.language = args.language
        self.level = args.level
        self.save_path = os.path.join(args.save_path, 'Problems[LV' + self.level + ']')
        self.file_extension = args.file_extension

    def printInfo(self):
        print("\n**********************************************************************************")
        print("Progarmmers Problem Crwaler")
        print("%-12s"%'id',':',self.id)
        print("%-12s"%'pw',':',self.pw)
        print("%-12s"%'language',':',self.language)
        print("%-12s"%'level',':',self.level)
        print("%-12s"%'save_path',':',self.save_path)
        print("%-12s"%'file_ext',':',self.file_extension)
        print("**********************************************************************************\n")

    def getUrl(self, lang, level, page):
        base_url = 'https://programmers.co.kr/learn/challenges?tab=all_challenges'
        base_url += ('&challenge_languages%5B%5D=' + lang)
        base_url += ('&challenge_levels%5B%5D=' + level)
        base_url += '&page=' + page
        return base_url

    def start(self):
        print("Loading......")
        # inter programmers
        self.driver.get("https://programmers.co.kr")
        self.driver.implicitly_wait(self.wait)
        print("get https://programmers.co.kr")

        ####################################  LOGIN  ####################################
        # go login window
        self.driver.get('https://programmers.co.kr/users/login')
        self.driver.implicitly_wait(self.wait)
        # input id
        self.driver.find_element_by_xpath('//*[@id="user_email"]').send_keys(self.id)           
        self.driver.implicitly_wait(self.wait)
        # input pw
        self.driver.find_element_by_xpath('//*[@id="user_password"]').send_keys(self.pw)                  
        self.driver.implicitly_wait(self.wait)
        # click login button
        webdriver.ActionChains(self.driver).key_down(Keys.ENTER).key_up(Keys.ENTER).perform()                               
        self.driver.implicitly_wait(self.wait)
        print("login complete")



        ####################################  PROBLEM SELECT  ####################################
        # problem selection
        self.driver.get(self.getUrl(self.language, self.level, '1'))
        self.driver.implicitly_wait(self.wait)
        time.sleep(0.3)
        # [prev, 1, 2,,,, next]
        pageable = self.driver.find_elements_by_xpath('/html/body/div[3]/div[3]/div/section/div/div[2]/div[2]/div[2]/*')
        page_count = 0 if not pageable else len(self.driver.find_elements_by_xpath('/html/body/div[3]/div[3]/div/section/div/div[2]/div[2]/div[2]/nav/ul/li'))
        print("getting problems...")
        problem_links = []
        # get problem id
        if page_count:
            for page in range(1, page_count-1):
                self.driver.get(self.getUrl(self.language, self.level, str(page)))
                self.driver.implicitly_wait(self.wait)
                problem_list = self.driver.find_elements_by_xpath('/html/body/div[3]/div[3]/div/section/div/div[2]/div[2]/div[1]/div')
                for p in problem_list:
                    link = p.find_element_by_xpath('div/a').get_property('href')
                    problem_links.append(link)

        else:
            problem_list = self.driver.find_elements_by_xpath('/html/body/div[3]/div[3]/div/section/div/div[2]/div[2]/div[1]/div')
            for p in problem_list:
                link = p.find_element_by_xpath('div/a').get_property('href')
                problem_links.append(link)



        ####################################  CRAWILNG START  ####################################
        print("start!")
        # start
        print(f'{self.language} LV:{self.level} {len(problem_links)}problem') 

        for p in tqdm(problem_links):
            self.driver.get(p + '?language=' + self.language)
            self.driver.implicitly_wait(self.wait)

            problem_name = self.driver.find_element_by_xpath('/html/body/div[1]/ol/li[3]').text
            print(problem_name)

            code = self.driver.find_element_by_xpath('/html/body/div[2]/div/div/div[1]/div[3]/div[1]/div/ul/input[2]').get_property("value")
            with open(os.path.join(self.save_path, ('[LV' + self.level + ']' + problem_name + '.' + self.file_extension)), 'w') as file:
                file.write(code)

        print("Complete")
        self.driver.close()


if __name__ == "__main__":
    crawler = Crawler()
    crawler.start()