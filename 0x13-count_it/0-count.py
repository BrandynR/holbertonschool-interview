#!/usr/bin/python3
"""keywords titles of all hot articles"""
import requests
import sys


def count_words(subreddit, word_list, keyword={}, nxtpg=None, repeat={}):
    """Uses keyword to find hot posts"""
    headers = {"User-Agent": "BrandynR"}

    if nxtpg:
        subRed = requests.get('https://reddit.com/r/' + subreddit +
                              '/hot.json?after=' + nxtpg,
                              headers=headers)
    else:
        subRed = requests.get('https://reddit.com/r/' + subreddit +
                              '/hot.json', headers=headers)

    if subRed.status_code == 404:
        return

    if keyword == {}:
        for word in word_list:
            keyword[word] = 0
            repeat[word] = word_list.count(word)

    sub_dict = subRed.json()
    sub_data = sub_dict['data']
    nxtpg = sub_data['after']
    sub_posts = sub_data['children']

    for post in sub_posts:
        post_data = post['data']
        post_title = post_data['title']
        title_words = post_title.split()
        for w in title_words:
            for key in keyword:
                if w.lower() == key.lower():
                    keyword[key] += 1

    if nxtpg:
        count_words(subreddit, word_list, keyword, nxtpg, repeat)

    else:
        for key, val in repeat.items():
            if val > 1:
                keyword[key] *= val

        sorted_abc = sorted(keyword.items(), key=lambda x: x[0])
        sorted_res = sorted(sorted_abc, key=lambda x: (-x[1], x[0]))
        for res in sorted_res:
            if res[1] > 0:
                print('{}: {}'.format(res[0], res[1]))
