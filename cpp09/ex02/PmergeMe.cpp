#include "PmergeMe.hpp"

std::size_t jacob[54] = {0u,
                         1u,
                         3u,
                         5u,
                         11u,
                         21u,
                         43u,
                         85u,
                         171u,
                         341u,
                         683u,
                         1365u,
                         2731u,
                         5461u,
                         10923u,
                         21845u,
                         43691u,
                         87381u,
                         174763u,
                         349525u,
                         699051u,
                         1398101u,
                         2796203u,
                         5592405u,
                         11184811u,
                         22369621u,
                         44739243u,
                         89478485u,
                         178956971u,
                         357913941u,
                         715827883u,
                         1431655765u,
                         2863311531u,
                         5726623061u,
                         11453246123u,
                         22906492245u,
                         45812984491u,
                         91625968981u,
                         183251937963u,
                         366503875925u,
                         733007751851u,
                         1466015503701u,
                         2932031007403u,
                         5864062014805u,
                         11728124029611u,
                         23456248059221u,
                         46912496118443u,
                         93824992236885u,
                         187649984473771u,
                         375299968947541u,
                         750599937895083u,
                         1501199875790165u,
                         3002399751580331u};

unsigned int PmergeMe::find_pair(std::vector<ipair>& pairs, unsigned int v) {
  for (unsigned int i = 0; i < pairs.size(); ++i) {
    if (pairs[i].second == v) {
      return pairs[i].first;
    }
  }
  return v;
}

void PmergeMe::print_vec(std::vector<unsigned int>& v) {
  for (unsigned int i = 0; i < v.size(); ++i) {
    std::cout << v[i] << " ";
  }
  std::cout << "\n";
}

vpair PmergeMe::set_pair(std::vector<unsigned int>& v) {
  unsigned int mid = v.size() / 2;
  std::vector<unsigned int> lv(mid);
  std::vector<unsigned int> sv(mid);
  for (unsigned int i = 0; i < mid; i++) {
    lv[i] = v[i];
    sv[i] = v[i + mid];
    if (lv[i] < sv[i]) {
      std::swap(lv[i], sv[i]);
    }
  }
  return std::make_pair(lv, sv);
}

std::vector<unsigned int> PmergeMe::insertion(std::vector<unsigned int>& cv,
                                              std::vector<unsigned int> sv,
                                              unsigned int idx) {
  if (jacob[idx - 1] >= cv.size()) {
    return cv;
  }
  std::size_t start = sv.size() > jacob[idx] ? jacob[idx] : sv.size();
  if (idx == 1) {
    cv.insert(cv.begin(), sv[0]);
    return insertion(cv, sv, idx + 1);
  }
  std::cout << "std::pow(2, idx) - 1 : " << std::pow(2, idx) - 1 << ", ";
  size_t end =
      std::pow(2, idx) - 1 > cv.size() ? cv.size() : std::pow(2, idx) - 1;
  for (std::size_t i = start - 1; i >= jacob[idx - 1]; --i) {
    cv.insert(std::lower_bound(cv.begin(), cv.begin() + end, sv[i]), sv[i]);
    if (i == 0) {
      break;
    }
  }
  std::cout << "\n";
  return insertion(cv, sv, idx + 1);
}

std::vector<unsigned int> PmergeMe::sorted(std::vector<unsigned int>& v) {
  unsigned int mid = v.size() / 2;
  std::vector<unsigned int> _cv;
  std::vector<unsigned int> lv(mid);
  std::vector<unsigned int> sv(mid);
  std::vector<ipair> pair_vector;
  unsigned int odd;
  if (v.size() % 2) {
    odd = v[v.size() - 1];
  }
  if (v.size() < 2) {
    _cv.push_back(v[0]);
    return _cv;
  }
  for (unsigned int i = 0; i < mid; i++) {
    lv[i] = v[i];
    sv[i] = v[i + mid];
    if (lv[i] < sv[i]) {
      std::swap(lv[i], sv[i]);
    }
    pair_vector.push_back(std::make_pair(sv[i], lv[i]));
  }
  _cv = sorted(lv);
  std::vector<unsigned int> _sv(sv.size());
  for (unsigned int i = 0; i < _sv.size(); ++i) {
    _sv[i] = find_pair(pair_vector, _cv[i]);
  }
  if (v.size() % 2) {
    _sv.push_back(odd);
  }
  std::cout << "_sv: ";
  print_vec(_sv);
  insertion(_cv, _sv, 1);
  std::cout << "_cv: ";
  print_vec(_cv);
  return _cv;
}
