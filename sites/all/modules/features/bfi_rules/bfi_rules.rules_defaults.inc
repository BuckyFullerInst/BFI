<?php
/**
 * @file
 * bfi_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function bfi_rules_default_rules_configuration() {
  $items = array();
  $items['rules_bfc_application_fee_paid'] = entity_import('rules_config', '{ "rules_bfc_application_fee_paid" : {
      "LABEL" : "BFC Application Fee Paid",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "payment", "rules_conditional", "bfi_project_review" ],
      "ON" : [ "payment_status_change", "payment_insert" ],
      "IF" : [
        { "data_is" : { "data" : [ "payment:field-payment-type" ], "value" : "24" } },
        { "payment_rules_condition_payment_status_is" : {
            "payment" : [ "payment" ],
            "payment_statuses" : { "value" : {
                "payment_status_money_transferred" : "payment_status_money_transferred",
                "payment_status_success" : "payment_status_success"
              }
            }
          }
        }
      ],
      "DO" : [
        { "entity_fetch" : {
            "USING" : { "type" : "entityform", "id" : [ "payment:field-payment-app-id" ] },
            "PROVIDE" : { "entity_fetched" : { "entityform" : "Entityform" } }
          }
        },
        { "CONDITIONAL" : [
            {
              "IF" : { "entity_has_field" : { "entity" : [ "entityform" ], "field" : "field_application_questions" } },
              "DO" : [
                { "entity_create" : {
                    "USING" : {
                      "type" : "node",
                      "param_type" : "project",
                      "param_title" : [ "entityform:field-application-questions:field-project-app-name" ],
                      "param_author" : [ "site:current-user" ]
                    },
                    "PROVIDE" : { "entity_created" : { "project_new" : "New Project" } }
                  }
                },
                { "bfi_project_review_action_copy_field_coll_to_node" : {
                    "source" : [ "entityform" ],
                    "node" : [ "project-new" ],
                    "field" : [ "entityform:field-application-questions" ]
                  }
                },
                { "component_rules_bfc_set_project_author_new_or_existing" : { "project" : [ "project-new" ] } },
                { "data_set" : {
                    "data" : [ "project-new:field-year" ],
                    "value" : [ "site:current-date" ]
                  }
                },
                { "data_set" : { "data" : [ "project-new:field-project-round" ], "value" : "0" } },
                { "data_set" : { "data" : [ "project-new:field-project-status" ], "value" : "14" } },
                { "entity_save" : { "data" : [ "project-new" ], "immediate" : 1 } },
                { "component_rules_bfc_set_payment_to_project" : { "entityform" : [ "entityform" ], "project_new" : [ "project_new" ] } },
                { "entity_delete" : { "data" : [ "entityform" ] } },
                { "drupal_message" : { "message" : "Thank you for submitting your application! Please make sure the details are correct. We will get in touch with you whenever stuff happens." } }
              ]
            }
          ]
        }
      ]
    }
  }');
  $items['rules_bfc_clear_project_reviews_after_delete_project'] = entity_import('rules_config', '{ "rules_bfc_clear_project_reviews_after_delete_project" : {
      "LABEL" : "BFC Clear Project Reviews after Delete Project",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "relation" ],
      "ON" : [ "relation_delete" ],
      "IF" : [
        { "data_is" : { "data" : [ "relation:relation-type" ], "value" : "bfc_evaluation" } },
        { "entity_is_of_type" : { "entity" : [ "relation:endpoints:0" ], "type" : "entityform" } }
      ],
      "DO" : [ { "entity_delete" : { "data" : [ "relation:endpoints:0" ] } } ]
    }
  }');
  $items['rules_bfc_dashboard_vbo_assign_reviewer'] = entity_import('rules_config', '{ "rules_bfc_dashboard_vbo_assign_reviewer" : {
      "LABEL" : "BFC Dashboard VBO Assign Reviewer",
      "PLUGIN" : "action set",
      "REQUIRES" : [ "bfi_project_review" ],
      "USES VARIABLES" : {
        "project" : { "label" : "Project", "type" : "node" },
        "reviewers" : { "label" : "Reviewers", "type" : "list\\u003Cuser\\u003E" }
      },
      "ACTION SET" : [
        { "LOOP" : {
            "USING" : { "list" : [ "reviewers" ] },
            "ITEM" : { "reviewer" : "Reviewer" },
            "DO" : [
              { "bfi_project_review_action_assign_reviewer_bulk" : { "project" : [ "project" ], "reviewer" : [ "reviewer" ] } }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_bfc_dashboard_vbo_take_out_reviewer'] = entity_import('rules_config', '{ "rules_bfc_dashboard_vbo_take_out_reviewer" : {
      "LABEL" : "BFC Dashboard VBO Take Out Reviewer",
      "PLUGIN" : "action set",
      "REQUIRES" : [ "bfi_project_review" ],
      "USES VARIABLES" : {
        "project" : { "label" : "Project", "type" : "node" },
        "reviewers" : { "label" : "Reviewers", "type" : "list\\u003Cuser\\u003E" }
      },
      "ACTION SET" : [
        { "LOOP" : {
            "USING" : { "list" : [ "reviewers" ] },
            "ITEM" : { "reviewer" : "Reviewer" },
            "DO" : [
              { "bfi_project_review_action_take_out_reviewer_bulk" : { "project" : [ "project" ], "reviewer" : [ "reviewer" ] } }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_bfc_project_application_submission'] = entity_import('rules_config', '{ "rules_bfc_project_application_submission" : {
      "LABEL" : "BFC Project Application Submission",
      "PLUGIN" : "rule",
      "TAGS" : [ "entityform submission" ],
      "REQUIRES" : [ "rules", "bfi_project_review", "rules_conditional" ],
      "USES VARIABLES" : {
        "entityform" : { "label" : "Submitted Entityform", "type" : "entityform" },
        "entityform_type" : { "label" : "Entityform Type", "type" : "entityform_type" }
      },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "entityform" ], "field" : "field_application_questions" } }
      ],
      "DO" : [
        { "bfi_project_review_action_ensure_unique_project" : {
            "USING" : { "app" : [ "entityform" ] },
            "PROVIDE" : { "nonu_projects" : { "nonu_projects" : "Non-unique Projects" } }
          }
        },
        { "CONDITIONAL" : [
            {
              "IF" : { "data_is" : { "data" : [ "nonu-projects" ], "value" : "0" } },
              "DO" : [
                { "CONDITIONAL" : [
                    {
                      "IF" : { "data_is" : {
                          "data" : [ "entityform:field-application-questions:field-project-applicant-type" ],
                          "value" : "full"
                        }
                      },
                      "DO" : [
                        { "redirect" : { "url" : "challenge\\/apply\\/payment?edit[field_payment_type][und]=24\\u0026edit[field_payment_app_id][und][0][value]=[entityform:entityform-id]" } }
                      ]
                    },
                    { "ELSE" : [
                        { "redirect" : { "url" : "challenge\\/apply\\/payment\\/discounted?edit[field_payment_type][und]=24\\u0026edit[field_payment_app_id][und][0][value]=[entityform:entityform-id]" } }
                      ]
                    }
                  ]
                },
                { "drupal_message" : { "message" : "Thank you for submitting your application! Please make sure the details are correct. We will get in touch with you whenever stuff happens." } }
              ]
            },
            { "ELSE" : [
                { "drupal_message" : {
                    "message" : "Sorry, a project has already been submitted with this email address. Project not accepted.",
                    "type" : "error"
                  }
                },
                { "entity_delete" : { "data" : [ "entityform" ] } },
                { "redirect" : { "url" : "apply" } }
              ]
            }
          ]
        }
      ]
    }
  }');
  $items['rules_bfc_project_edit'] = entity_import('rules_config', '{ "rules_bfc_project_edit" : {
      "LABEL" : "BFC Project Edit",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "rules_conditional" ],
      "ON" : [ "node_update" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "project" : "project" } } } }
      ],
      "DO" : [
        { "CONDITIONAL" : [
            {
              "IF" : { "data_is" : { "data" : [ "node-unchanged:field-project-status" ], "value" : "14" } },
              "DO" : [
                { "SWITCH" : {
                    "USING" : { "data" : [ "node:field-project-status" ] },
                    "DO" : [
                      { "CASE" : { "USING" : { "value" : "17" }, "DO" : [] } },
                      { "CASE" : {
                          "USING" : { "value" : "15" },
                          "DO" : [
                            { "component_rules_bfc_set_project_author_new_or_existing" : { "project" : [ "node" ] } },
                            { "data_set" : { "data" : [ "node:field-project-round" ], "value" : "1" } }
                          ]
                        }
                      }
                    ]
                  }
                }
              ]
            }
          ]
        }
      ]
    }
  }');
  $items['rules_bfc_project_load'] = entity_import('rules_config', '{ "rules_bfc_project_load" : {
      "LABEL" : "BFC Project Load",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "bfi_project_review", "rules" ],
      "ON" : [ "node_view" ],
      "DO" : [ { "bfi_project_review_action_dpm_project" : [] } ]
    }
  }');
  $items['rules_bfc_project_review_assign_reviewer_if_not_assigned'] = entity_import('rules_config', '{ "rules_bfc_project_review_assign_reviewer_if_not_assigned" : {
      "LABEL" : "BFC Project Review Assign Reviewer if not Assigned",
      "PLUGIN" : "action set",
      "REQUIRES" : [ "bfi_project_review" ],
      "USES VARIABLES" : { "reviewer" : { "label" : "Reviewer", "type" : "user" } },
      "ACTION SET" : [
        { "bfi_project_review_action_assign_reviewer_if_not" : { "reviewer" : [ "reviewer" ] } }
      ]
    }
  }');
  $items['rules_bfc_project_review_edit'] = entity_import('rules_config', '{ "rules_bfc_project_review_edit" : {
      "LABEL" : "BFC Project Review Edit",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "bfi_project_review", "rules", "entityform" ],
      "ON" : [ "entityform_update" ],
      "DO" : [
        { "bfi_project_review_action_fetch_project" : {
            "USING" : { "review_current" : [ "entityform" ] },
            "PROVIDE" : { "project_current" : { "project_current" : "Current Project" } }
          }
        },
        { "redirect" : { "url" : [ "project-current:url" ] } }
      ]
    }
  }');
  $items['rules_bfc_project_review_take_out_reviewer'] = entity_import('rules_config', '{ "rules_bfc_project_review_take_out_reviewer" : {
      "LABEL" : "BFC Project Review Take Out Reviewer",
      "PLUGIN" : "action set",
      "REQUIRES" : [ "bfi_project_review" ],
      "USES VARIABLES" : { "reviewer" : { "label" : "Reviewer", "type" : "user" } },
      "ACTION SET" : [
        { "bfi_project_review_action_take_out_reviewer" : { "reviewer" : [ "reviewer" ] } }
      ]
    }
  }');
  $items['rules_bfc_review_note_submission'] = entity_import('rules_config', '{ "rules_bfc_review_note_submission" : {
      "LABEL" : "BFC Review Note Submission",
      "PLUGIN" : "rule",
      "TAGS" : [ "entityform submission" ],
      "REQUIRES" : [ "rules", "bfi_project_review" ],
      "USES VARIABLES" : {
        "entityform" : { "label" : "Submitted Entityform", "type" : "entityform" },
        "entityform_type" : { "label" : "Entityform Type", "type" : "entityform_type" }
      },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "entityform" ], "field" : "field_project_review_note" } }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "list\\u003Centity\\u003E", "value" : [ "" ] },
            "PROVIDE" : { "variable_added" : { "list_assignment" : "Assignment Relation List" } }
          }
        },
        { "list_add" : { "list" : [ "list-assignment" ], "item" : [ "site:current-user" ] } },
        { "component_rules_tckdesign_load_current_node_from_page" : { "PROVIDE" : { "node_current" : { "project_current" : "Current Project" } } } },
        { "list_add" : { "list" : [ "list-assignment" ], "item" : [ "project-current" ] } },
        { "variable_add" : {
            "USING" : { "type" : "list\\u003Centity\\u003E", "value" : [ "" ] },
            "PROVIDE" : { "variable_added" : { "list_review" : "Review Relation List" } }
          }
        },
        { "list_add" : { "list" : [ "list-review" ], "item" : [ "entityform" ], "pos" : "start" } },
        { "list_add" : { "list" : [ "list-review" ], "item" : [ "project-current" ] } },
        { "entity_create" : {
            "USING" : {
              "type" : "relation",
              "param_relation_type" : "bfc_evaluation",
              "param_endpoints" : [ "list-review" ]
            },
            "PROVIDE" : { "entity_created" : { "eval_new" : "New Evaluation" } }
          }
        },
        { "component_rules_set_eval_note_round_based_on_project_round" : { "project_current" : [ "project_current" ], "eval_new" : [ "eval_new" ] } },
        { "component_rules_bfc_set_up_round_fields_in_project_ave_score_colls" : { "project" : [ "project-current" ] } },
        { "entity_save" : { "data" : [ "project-current" ], "immediate" : 1 } },
        { "entity_save" : { "data" : [ "eval-new" ], "immediate" : 1 } },
        { "bfi_project_review_action_review_in" : { "project" : [ "project-current" ] } },
        { "redirect" : { "url" : [ "project-current:url" ] } }
      ]
    }
  }');
  $items['rules_bfc_set_payment_to_project'] = entity_import('rules_config', '{ "rules_bfc_set_payment_to_project" : {
      "LABEL" : "BFC Set Payment to Project",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "entityform" : { "label" : "Entityform", "type" : "entityform" },
        "project_new" : { "label" : "New Project", "type" : "node" }
      },
      "DO" : [
        { "entity_query" : {
            "USING" : {
              "type" : "payment",
              "property" : "field_payment_app_id",
              "value" : [ "entityform:entityform-id" ],
              "limit" : "1"
            },
            "PROVIDE" : { "entity_fetched" : { "payment_list" : "Payment List" } }
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "list\\u003Centity\\u003E", "value" : [ "" ] },
            "PROVIDE" : { "variable_added" : { "payment_new_list" : "New Payment List" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "payment-list" ] },
            "ITEM" : { "payment_current" : "Current Payment" },
            "DO" : [
              { "list_add" : {
                  "list" : [ "payment-new-list" ],
                  "item" : [ "payment-current" ],
                  "pos" : "start"
                }
              }
            ]
          }
        },
        { "list_add" : { "list" : [ "payment-new-list" ], "item" : [ "project-new" ] } },
        { "entity_create" : {
            "USING" : {
              "type" : "relation",
              "param_relation_type" : "bfc_payment",
              "param_endpoints" : [ "payment-new-list" ]
            },
            "PROVIDE" : { "entity_created" : { "payment_new" : "New Payment Rel" } }
          }
        },
        { "entity_save" : { "data" : [ "payment-new" ], "immediate" : 1 } }
      ]
    }
  }');
  $items['rules_bfc_set_project_author_new_or_existing'] = entity_import('rules_config', '{ "rules_bfc_set_project_author_new_or_existing" : {
      "LABEL" : "BFC Set Project Author (new or existing)",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules", "bfi_project_review" ],
      "USES VARIABLES" : { "project" : { "label" : "Project", "type" : "node" } },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "project" ],
            "type" : { "value" : { "project" : "project" } }
          }
        }
      ],
      "DO" : [
        { "bfi_project_review_action_attach_project_to_user" : {
            "USING" : { "project" : [ "project" ] },
            "PROVIDE" : { "user_rid" : { "user_rid" : "User to attach to" } }
          }
        },
        { "entity_fetch" : {
            "USING" : { "type" : "user", "id" : [ "user-rid" ] },
            "PROVIDE" : { "entity_fetched" : { "applicant" : "Applicant" } }
          }
        },
        { "data_set" : { "data" : [ "project:author" ], "value" : [ "applicant" ] } },
        { "user_add_role" : { "account" : [ "applicant" ], "roles" : { "value" : { "12" : "12" } } } },
        { "data_set" : { "data" : [ "applicant:field-project-app-user-applied" ], "value" : 1 } }
      ]
    }
  }');
  $items['rules_bfc_set_up_round_fields_in_project_ave_score_colls'] = entity_import('rules_config', '{ "rules_bfc_set_up_round_fields_in_project_ave_score_colls" : {
      "LABEL" : "BFC Set up Round Field in Project Ave Score Coll",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules", "rules_conditional" ],
      "USES VARIABLES" : { "project" : { "label" : "Project", "type" : "node" } },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "project" ], "field" : "field_project_review_score_rds" } },
        { "entity_has_field" : { "entity" : [ "project" ], "field" : "field_project_round" } }
      ],
      "DO" : [
        { "SWITCH" : {
            "USING" : { "data" : [ "project:field-project-round" ] },
            "DO" : [
              { "CASE" : {
                  "USING" : { "value" : "1" },
                  "DO" : [
                    { "data_set" : {
                        "data" : [ "project:field-project-review-score-rds:0:field-project-round-eval" ],
                        "value" : "1"
                      }
                    }
                  ]
                }
              },
              { "CASE" : {
                  "USING" : { "value" : "2" },
                  "DO" : [
                    { "data_set" : {
                        "data" : [ "project:field-project-review-score-rds:1:field-project-round-eval" ],
                        "value" : "2"
                      }
                    }
                  ]
                }
              },
              { "CASE" : {
                  "USING" : { "value" : "3" },
                  "DO" : [
                    { "data_set" : {
                        "data" : [ "project:field-project-review-score-rds:2:field-project-round-eval" ],
                        "value" : "3"
                      }
                    }
                  ]
                }
              },
              { "CASE" : {
                  "USING" : { "value" : "4" },
                  "DO" : [
                    { "data_set" : {
                        "data" : [ "project:field-project-review-score-rds:3:field-project-round-eval" ],
                        "value" : "4"
                      }
                    }
                  ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_bfi_sync_menu_ref_with_parent_menu_item'] = entity_import('rules_config', '{ "rules_bfi_sync_menu_ref_with_parent_menu_item" : {
      "LABEL" : "BFI Sync Menu Ref with Parent Menu Item",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules" ],
      "ON" : [ "menu_rules_menu_link_insert" ],
      "DO" : [ { "drupal_message" : { "message" : "hooray!" } } ]
    }
  }');
  $items['rules_set_eval_note_round_based_on_project_round'] = entity_import('rules_config', '{ "rules_set_eval_note_round_based_on_project_round" : {
      "LABEL" : "Set Eval Note Round Based on Project Round",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "project_current" : { "label" : "Current Project", "type" : "node" },
        "eval_new" : { "label" : "New Evaluation", "type" : "relation" }
      },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "project-current" ], "field" : "field_project_round" } },
        { "entity_has_field" : { "entity" : [ "eval-new" ], "field" : "field_project_round_eval" } }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "eval-new:field-project-round-eval" ],
            "value" : [ "project-current:field-project-round" ]
          }
        }
      ]
    }
  }');
  $items['rules_tckdesign_load_current_node_from_page'] = entity_import('rules_config', '{ "rules_tckdesign_load_current_node_from_page" : {
      "LABEL" : "TCKDesign Load Current Node from Page",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "php", "rules" ],
      "USES VARIABLES" : { "node_current" : { "label" : "Current Node", "type" : "node", "parameter" : false } },
      "DO" : [
        { "variable_add" : {
            "USING" : {
              "type" : "text",
              "value" : {
                "select" : "site:current-page:path",
                "php" : { "code" : "return substr($value, 5);" }
              }
            },
            "PROVIDE" : { "variable_added" : { "path_current_text" : "Current Path Text" } }
          }
        },
        { "data_convert" : {
            "USING" : { "type" : "integer", "value" : [ "path-current-text" ] },
            "PROVIDE" : { "conversion_result" : { "path_current_integer" : "Current Path Integer" } }
          }
        },
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "path-current-integer" ] },
            "PROVIDE" : { "entity_fetched" : { "node_loaded" : "Loaded Node" } }
          }
        },
        { "data_set" : { "data" : [ "node-current" ], "value" : [ "node-loaded" ] } }
      ],
      "PROVIDES VARIABLES" : [ "node_current" ]
    }
  }');
  return $items;
}
