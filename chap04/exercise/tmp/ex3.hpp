// Code generated by Stan version 2.14

#include <stan/model/model_header.hpp>

namespace ex3_model_namespace {

using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;

typedef Eigen::Matrix<double,Eigen::Dynamic,1> vector_d;
typedef Eigen::Matrix<double,1,Eigen::Dynamic> row_vector_d;
typedef Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> matrix_d;

static int current_statement_begin__;

class ex3_model : public prob_grad {
private:
    int N1;
    int N2;
    vector<double> Y1;
    vector<double> Y2;
public:
    ex3_model(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        typedef boost::ecuyer1988 rng_t;
        rng_t base_rng(0);  // 0 seed default
        ctor_body(context__, base_rng, pstream__);
    }

    template <class RNG>
    ex3_model(stan::io::var_context& context__,
        RNG& base_rng__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, base_rng__, pstream__);
    }

    template <class RNG>
    void ctor_body(stan::io::var_context& context__,
                   RNG& base_rng__,
                   std::ostream* pstream__) {
        current_statement_begin__ = -1;

        static const char* function__ = "ex3_model_namespace::ex3_model";
        (void) function__; // dummy call to supress warning
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        double DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        // initialize member variables
        context__.validate_dims("data initialization", "N1", "int", context__.to_vec());
        N1 = int(0);
        vals_i__ = context__.vals_i("N1");
        pos__ = 0;
        N1 = vals_i__[pos__++];
        context__.validate_dims("data initialization", "N2", "int", context__.to_vec());
        N2 = int(0);
        vals_i__ = context__.vals_i("N2");
        pos__ = 0;
        N2 = vals_i__[pos__++];
        context__.validate_dims("data initialization", "Y1", "double", context__.to_vec(N1));
        validate_non_negative_index("Y1", "N1", N1);
        Y1 = std::vector<double>(N1,double(0));
        vals_r__ = context__.vals_r("Y1");
        pos__ = 0;
        size_t Y1_limit_0__ = N1;
        for (size_t i_0__ = 0; i_0__ < Y1_limit_0__; ++i_0__) {
            Y1[i_0__] = vals_r__[pos__++];
        }
        context__.validate_dims("data initialization", "Y2", "double", context__.to_vec(N2));
        validate_non_negative_index("Y2", "N2", N2);
        Y2 = std::vector<double>(N2,double(0));
        vals_r__ = context__.vals_r("Y2");
        pos__ = 0;
        size_t Y2_limit_0__ = N2;
        for (size_t i_0__ = 0; i_0__ < Y2_limit_0__; ++i_0__) {
            Y2[i_0__] = vals_r__[pos__++];
        }

        // validate, data variables
        // initialize data variables

        try {
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e,current_statement_begin__);
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        // validate transformed data

        // set parameter ranges
        num_params_r__ = 0U;
        param_ranges_i__.clear();
        ++num_params_r__;
        ++num_params_r__;
        ++num_params_r__;
    }

    ~ex3_model() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        stan::io::writer<double> writer__(params_r__,params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        if (!(context__.contains_r("mu1")))
            throw std::runtime_error("variable mu1 missing");
        vals_r__ = context__.vals_r("mu1");
        pos__ = 0U;
        context__.validate_dims("initialization", "mu1", "double", context__.to_vec());
        // generate_declaration mu1
        double mu1(0);
        mu1 = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(mu1);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable mu1: ") + e.what());
        }

        if (!(context__.contains_r("mu2")))
            throw std::runtime_error("variable mu2 missing");
        vals_r__ = context__.vals_r("mu2");
        pos__ = 0U;
        context__.validate_dims("initialization", "mu2", "double", context__.to_vec());
        // generate_declaration mu2
        double mu2(0);
        mu2 = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(mu2);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable mu2: ") + e.what());
        }

        if (!(context__.contains_r("sigma")))
            throw std::runtime_error("variable sigma missing");
        vals_r__ = context__.vals_r("sigma");
        pos__ = 0U;
        context__.validate_dims("initialization", "sigma", "double", context__.to_vec());
        // generate_declaration sigma
        double sigma(0);
        sigma = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,sigma);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable sigma: ") + e.what());
        }

        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }


    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(vector<T__>& params_r__,
                 vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        T__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;

        // model parameters
        stan::io::reader<T__> in__(params_r__,params_i__);

        T__ mu1;
        (void) mu1;  // dummy to suppress unused var warning
        if (jacobian__)
            mu1 = in__.scalar_constrain(lp__);
        else
            mu1 = in__.scalar_constrain();

        T__ mu2;
        (void) mu2;  // dummy to suppress unused var warning
        if (jacobian__)
            mu2 = in__.scalar_constrain(lp__);
        else
            mu2 = in__.scalar_constrain();

        T__ sigma;
        (void) sigma;  // dummy to suppress unused var warning
        if (jacobian__)
            sigma = in__.scalar_lb_constrain(0,lp__);
        else
            sigma = in__.scalar_lb_constrain(0);


        // transformed parameters


        try {
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e,current_statement_begin__);
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        // validate transformed parameters

        const char* function__ = "validate transformed params";
        (void) function__;  // dummy to suppress unused var warning

        // model body
        try {

            current_statement_begin__ = 15;
            for (int n = 1; n <= N1; ++n) {

                current_statement_begin__ = 16;
                lp_accum__.add(normal_log<propto__>(get_base1(Y1,n,"Y1",1), mu1, sigma));
            }
            current_statement_begin__ = 19;
            for (int n = 1; n <= N2; ++n) {

                current_statement_begin__ = 20;
                lp_accum__.add(normal_log<propto__>(get_base1(Y2,n,"Y2",1), mu2, sigma));
            }
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e,current_statement_begin__);
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()

    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("mu1");
        names__.push_back("mu2");
        names__.push_back("sigma");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        vars__.resize(0);
        stan::io::reader<double> in__(params_r__,params_i__);
        static const char* function__ = "ex3_model_namespace::write_array";
        (void) function__; // dummy call to supress warning
        // read-transform, write parameters
        double mu1 = in__.scalar_constrain();
        double mu2 = in__.scalar_constrain();
        double sigma = in__.scalar_lb_constrain(0);
        vars__.push_back(mu1);
        vars__.push_back(mu2);
        vars__.push_back(sigma);

        if (!include_tparams__) return;
        // declare and define transformed parameters
        double lp__ = 0.0;
        (void) lp__; // dummy call to supress warning
        stan::math::accumulator<double> lp_accum__;

        double DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning



        try {
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e,current_statement_begin__);
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        // validate transformed parameters

        // write transformed parameters

        if (!include_gqs__) return;
        // declare and define generated quantities


        try {
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e,current_statement_begin__);
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        // validate generated quantities

        // write generated quantities
    }

    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng,params_r_vec,params_i_vec,vars_vec,include_tparams,include_gqs,pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }

    static std::string model_name() {
        return "ex3_model";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu1";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu2";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;

        if (!include_gqs__) return;
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu1";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "mu2";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;

        if (!include_gqs__) return;
    }

}; // model

} // namespace

typedef ex3_model_namespace::ex3_model stan_model;

