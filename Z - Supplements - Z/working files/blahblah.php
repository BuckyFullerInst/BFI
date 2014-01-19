<?php
  // For COMPREHENSIVE
  $result = array();
  $result[0] = $result[1] = $result[2] = $result[3] = '-';
  foreach ($data->_field_data as $field_coll) {
    if ($field_coll['entity_type'] == 'field_collection_item' && isset($field_coll['entity']->field_project_round_eval[LANGUAGE_NONE][0]['value'])) {
      $round = intval($field_coll['entity']->field_project_round_eval[LANGUAGE_NONE][0]['value']);
      $result[$round - 1] = $field_coll['entity']->field_project_review_ave_comp[LANGUAGE_NONE][0]['value'];
    }
  }
  echo $result[0].'<br />'.$result[1].'<br />'.$result[2].'<br />'.$result[3];
?>